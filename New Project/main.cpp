// CIS 2252 - Assignment 2 / 2015.07.17 / Alex Karpowitsch 

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>


using namespace std;

const int NUM_STUDENTS = 10;

// Returns true if all files read successfully
void ReadFiles(string namesArray[], int proj1Array[], int proj2Array[], int testArray[]) 
{
    ifstream inFile;
    bool errorOcurred = false;
    
    // Read Names.txt
	inFile.open("Names.txt");
    if (inFile.fail())
    {
        cout << "Failed to open Names.txt" << endl;
    }
    else 
    {
        for (int i = 0; i < NUM_STUDENTS; i++)
        {
            // Get the entire line with whitespace
            if ( !getline(inFile, namesArray[i]) ) {
                break;
            }
        }
        inFile.close();
    }
	
    // Read Proj1.txt
	inFile.open("Proj1.txt");
    if (inFile.fail())
    {
        cout << "Failed to open Proj1.txt" << endl;
    }
    else 
    {
        for (int i = 0; i < NUM_STUDENTS && !inFile.eof(); i++)
        {
            inFile >> proj1Array[i];
        }
        inFile.close();
    }

    // Read Proj2.txt
	inFile.open("Proj2.txt");
    if (inFile.fail())
    {
        cout << "Failed to open Proj2.txt" << endl;
    }
    else 
    {
        for (int i = 0; i < NUM_STUDENTS && !inFile.eof(); i++)
        {
            inFile >> proj2Array[i];
        }
        inFile.close();
    }

    // Read Test.txt
	inFile.open("Test.txt");
	if (inFile.fail())
    {
        cout << "Failed to open Test.txt" << endl;
    }
    else 
    {
        while (!inFile.eof())
        {
            for (int i = 0; i < NUM_STUDENTS; i++)
            {
                inFile >> testArray[i];
            }
        }
        inFile.close();
    }
}

string GetLetterGrade(float average)
{
    string result = "";
    
    if (95 <= average && average <= 100)
        result = "A";
    else if (90 <= average && average <= 94)
        result = "A-";
    else if (86 <= average && average <= 89)
        result = "B+";
    else if (83 <= average && average <= 85)
        result = "B";
    else if (80 <= average && average <= 82)
        result = "B-";
    else if (76 <= average && average <= 79)
        result = "C+";
    else if (73 <= average && average <= 75)
        result = "C";
    else if (70 <= average && average <= 72)
        result = "C-";
    else if (66 <= average && average <= 69)
        result = "D+";
    else if (60 <= average && average <= 65)
        result = "D";
    else if (average <= 60)
        result = "F";
    
    return result;
}

void DisplayData(string namesArray[], int proj1Array[], int proj2Array[], int testArray[])
{
    cout << setw(20) << left << "Name" 
         << setw(10) << left << "Proj1" 
         << setw(10) << left << "Proj2"
         << setw(10) << left << "Test"
         << setw(10) << left << "Average"
         << setw(10) << left << "Grade"
         << endl;
         
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        // Calc the average
        float average = ( proj1Array[i] + proj2Array[i] + testArray[i] ) / 3;
        
        // Determine the grade letter based on the rounded average
        string grade = GetLetterGrade(ceil(average));
        
        cout << fixed << setprecision(2)
             << setw(20) << left << namesArray[i]
             << setw(10) << left << proj1Array[i] 
             << setw(10) << left << proj2Array[i]
             << setw(10) << left << testArray[i]
             << setw(10) << left << average
             << setw(10) << left << grade
             << endl;
    }
}

int main()
{
    string namesArray[NUM_STUDENTS];
    int proj1Array[NUM_STUDENTS];
    int proj2Array[NUM_STUDENTS];
    int testArray[NUM_STUDENTS];

    ReadFiles(namesArray, proj1Array, proj2Array, testArray);
    
    DisplayData(namesArray, proj1Array, proj2Array, testArray);
    
	return 0;
}


