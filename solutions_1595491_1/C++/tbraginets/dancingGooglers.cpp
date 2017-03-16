#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

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
    
    for(int i = 0; i < numOfTestCases; i++)
    {
        getline(fileIn, line);
        stringstream ss(line);
        
        int numOfGooglers;
        int numOfSurprisingScoresAllowed;
        int bestResult;
        vector<int> totalScores;
        
        ss >> numOfGooglers;
        ss >> numOfSurprisingScoresAllowed;
        ss >> bestResult;
        for(int j = 0; j < numOfGooglers; j++)
        {
            int temp;
            ss >> temp;
            totalScores.push_back(temp);
        }
        
        int numOfTotalScoresWithBestResult = 0;
        int numSurprising = 0;
        int numSurprisingOrNot = 0;
        for(int j = 0; j < numOfGooglers; j++)
        {
            if(totalScores[j] == 0)
            {
                continue;
            }
            int avScore = totalScores[j] / 3;
            if(avScore >= bestResult || 
               ((bestResult - avScore) == 1 && (totalScores[j] - 2 * avScore) >= bestResult))
            {
                numOfTotalScoresWithBestResult++;
                numSurprisingOrNot++;
            }
            else if( (bestResult - avScore) == 1
                    || ( (bestResult - avScore) == 2 && (totalScores[j] - 2 * avScore) == bestResult )  )
            {
                numOfTotalScoresWithBestResult++;
                numSurprising++;
            }
        }
        
        int finalTotal = numOfTotalScoresWithBestResult;
        if(bestResult == 0)
        {
            finalTotal = numOfGooglers;
        }
        else if(numSurprising > numOfSurprisingScoresAllowed)
        {
            finalTotal -= (numSurprising - numOfSurprisingScoresAllowed);
        }
        
        fileOut << "Case #" << i + 1 << ": " << finalTotal << endl;
    }
    return 0;
}
