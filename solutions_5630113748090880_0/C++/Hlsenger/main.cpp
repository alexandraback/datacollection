#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <cstdlib>
#include <cstring>

#define IN_FILE "B-small-attempt1.in"
#define OUT_FILE "out"

using namespace std;

//Helpers
void writeOut(ofstream &outStream, int index, string content)
{
	outStream << "Case #" << index + 1 << ": " << content << endl;
	cout << "Case #" << index + 1 << ": " << content << endl;
}




int main(int argc, char *argv[])
{
	ifstream in;
	ofstream out;
	int numCases,N;
	std::string line;

	in.open(IN_FILE);
	if (in.fail())
	{
		cout << "Failed to open IN file \n";
	}
	out.open(OUT_FILE);

	//Read the number of cases
	in >> numCases;

	for (int i = 0; i < numCases; i++)
	{
		in >> N;

		vector<int> soldiers;
		vector<int> missingList;
		int height;

		//Read all the lines into an vector
		for (int j = 0; j < (N * 2) - 1; j++)
		{
			for (int k = 0; k < N; k++)
			{
				in >> height;
				soldiers.push_back(height);
			}
		}

		sort(soldiers.begin(), soldiers.end());

		//Find all soldiers without a pair
		int j = 0;
		while (j < soldiers.size() -1)
		{
			if (soldiers[j] != soldiers[j + 1] )
			{
				missingList.push_back(soldiers[j]);
				j += 1;
			}
			else
			{
				j += 2;
				
			}

			if (j == soldiers.size() - 1)
			{
				missingList.push_back(soldiers[j]);
			}
		}

		string missingOut = "";
		for (int j = 0; j < missingList.size(); j++)
		{
			missingOut +=  to_string( missingList[j]);
			if(j < missingList.size()-1)
				missingOut += " ";
		}

		writeOut(out, i, missingOut);

	}



	system("PAUSE");

	in.close();
	out.close();
}