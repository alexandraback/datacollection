#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

bool myfunction (int i,int j) { return (i<j); }

int main()
{
   string line;
   int numtc;
   ifstream myfile ("A-large1.in");
//	ifstream myfile ("input.txt");
   getline (myfile,line);
   numtc = atoi(line.c_str());

	int armin=0;
	int N=0;
	vector<int> vecMotes;

//cout << "NUMTC=" << numtc<<endl;
//test
//numtc=1;

	for(int testCaseNum=1; testCaseNum <= numtc; testCaseNum++)
	{
		if (myfile.is_open())
		{
			myfile >> armin;
			myfile >> N;
			int temp;

			vecMotes.clear();
			for(int i=0; i<N; i++)
			{
				myfile>>temp;
				vecMotes.push_back(temp);

			}

		}

		sort (vecMotes.begin(), vecMotes.end(), myfunction);

		int changes=0;
		int minSoln = N;
		for(int i=0; i<N; i++)
		{
			if(armin ==1) break;

			int currMote = vecMotes[i];
			if(armin > currMote)
			{
				armin+=currMote;
			}
			else
			{
				while(armin <= currMote)
				{
					armin += armin-1;
					changes++;
				}
				armin+=currMote;
			}

			if(changes >= minSoln)
				break;

			minSoln = (N-i-1 + changes < minSoln) ? N-i-1 + changes: minSoln;

		}


/*
cout <<"armin="<< armin <<endl;
cout <<"N="<< N <<endl;
for(int i=0; i<N; i++)
cout << vecMotes[i] << " ";
cout << endl;
*/


		cout << "Case #"<< testCaseNum << ": " << minSoln << endl;
	}

}
