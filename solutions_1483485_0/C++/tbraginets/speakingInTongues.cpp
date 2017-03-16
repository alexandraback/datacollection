#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int main (int argc, char * const argv[]) 
{
    ifstream fileIn("in.txt");
	if(!fileIn)
	{
		cout << "Couldn't open the file for reading" << endl;
        exit(0);
	}
    
    ofstream fileOut("out.txt");
    if(!fileOut)
    {
        cout << "Couldn't open the file for writing" << endl;
        exit(0);
    }
    
	string line;
    getline(fileIn, line);
    stringstream ssNum(line);
	int numOfTestCases;
    ssNum >> numOfTestCases;
    
    string alphabet = "yhesocvxduiglbkrztnwjpfmaq"; // mapped from examples
    
    for(int i = 0; i < numOfTestCases; i++)
    {
        string text;
        getline(fileIn, text);
        string outText;
        
        for(int j = 0; j < text.size(); j++)
        {
            char c = text[j];
            if(c != ' ')
            {
                c = alphabet[c - 'a'];
            }
            outText.push_back(c);
        }
        
        fileOut << "Case #" << i + 1 << ": " << outText << endl;
    }
    return 0;
}
