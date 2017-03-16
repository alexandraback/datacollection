#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <cstdlib>
#include <cstring>

#define IN_FILE "A-small.in"
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
	int numCases;
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
		in >> line;


		vector<char> finalWord;
		finalWord.push_back(line[0]);

		for (int j = 1; j < line.length(); j++)
		{

			if (int(line[j]) < int(finalWord[0]))
			{
				finalWord.push_back(line[j]);
			}
			else
			{
				finalWord.insert(finalWord.begin(), line[j]);
			}
		}

		//Turn into a string
		string finalString = "";

		for (int j = 0; j < finalWord.size(); j++)
		{
			finalString += finalWord[j];
		}


		writeOut(out, i, finalString);
	}



	in.close();
	out.close();
}