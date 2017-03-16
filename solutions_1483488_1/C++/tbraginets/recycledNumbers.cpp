#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int findNumM(int numN, int numB,  int n);

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
    
	int numOfTestCases;
    fileIn >> numOfTestCases;
    
    for(int i = 0; i < numOfTestCases; i++)
    {
        int numA;
        int numB;
        
        fileIn >> numA;
        fileIn >> numB;

        int numOfPairs = 0;
        map<int,int> storePairs;
        for(int k = numA; k < numB; k++)
        {
            stringstream ss;
            ss << k;
            string stringN = ss.str();
            for(int j = 1; j < stringN.size(); j++)
            {
                int numM = findNumM(k, numB, j);
                if((numM != -1) && storePairs[numM] != k)
                {
                    numOfPairs++;
                    storePairs[numM] = k;
                }
            }
        }
        
        fileOut << "Case #" << i + 1 << ": " << numOfPairs << endl;
    }
    return 0;
}

int findNumM(int numN, int numB,  int n)
{
    stringstream ssN;
    ssN << numN;
    string stringN = ssN.str();
    string lastPart = stringN.substr(stringN.size() - n, n);
    string firstPart = stringN.substr(0, stringN.size() - n);
    string stringM = lastPart.append(firstPart);
    stringstream ssM(stringM);
    int numM;
    ssM >> numM;
    if(numM <= numB && numM > numN)
    {
        return numM;
    }
    return -1;
}
