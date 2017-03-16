#include <algorithm>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

string intToString(int x)
{
	string result;
	char temp[256];
	_itoa_s(x,temp,255,10);
	result=temp;
	return result;
}

int stringToInt(string s)
{
	return atoi(s.c_str());
}

int vectorSum(vector<int> theVector)
{
	int result = 0;
	if (theVector.empty())
		return result;
	for (int i = 0; i < theVector.size(); i++)
	{
		result += theVector[i];
	}
	return result;
}

void findAllAncestors(const vector<vector<int>> &classStructure, vector<int> &inheritFrom, int node)
{
	if (classStructure[node].empty())
	{
		return;
	}
	else
	{
		for (int i = 0; i < classStructure[node].size(); i++)
		{
			inheritFrom.push_back(classStructure[node][i]);
			findAllAncestors(classStructure, inheritFrom, classStructure[node][i]);
		}
	}
}

string solveIt(ofstream & fout, FILE * pFile)
{
	int numOfClasses;
	fscanf(pFile, "%d", &numOfClasses);
	vector<vector<int>> classStructure;
	for (int i = 0; i < numOfClasses; i++)
	{
		classStructure.push_back(vector<int>());
		int classI;
		fscanf(pFile, "%d", &classI);
		for (int j = 0; j < classI; j++)
		{
			int inheritsFrom;
			fscanf(pFile, "%d", &inheritsFrom);
			classStructure[i].push_back(inheritsFrom - 1);	//This way classes are numbered 0, 1, 2, ...
		}
	}

	for (int i = 0; i < classStructure.size(); i++)
	{
		vector<int> inheritFrom;
		findAllAncestors(classStructure, inheritFrom, i);
		for (int j = 0; j < numOfClasses; j++)
		{
			if (count(inheritFrom.begin(), inheritFrom.end(), j) > 1)
			{
				return "Yes";
			}
		}
	}

	return "No";
}

int main()
{
	FILE * pFile;
	pFile = fopen("input.in", "r");

	ofstream fout;
	fout.open("output.txt");	//This is where we'll be putting the answers.

	int testCases;
	fscanf(pFile, "%d", &testCases);
	
	for (int i = 0; i < testCases; i++)	//Do what needs to be done for each test case.
	{
		fout << "Case #" << i + 1 << ": " << solveIt(fout, pFile) << endl;	//Put an answer here.
	}

	fout.close();
	return 0;
}