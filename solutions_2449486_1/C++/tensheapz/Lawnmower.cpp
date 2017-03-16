#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

string problemFile = "B-large";

//Globals
fstream input;
fstream output;
int CaseNum; //track what case # we are up to

//Declarations
void SolveInstance();

template <class T>
void LoadVector(vector<T>& v, int n) 
{
	int i, x;
	for (i = 0; i < n; ++i)
	{
		input >> x;
		v.push_back(x);
	}
}


int main()
{
	input.open(problemFile+".in", ios::in);
	output.open(problemFile+".out", ios::out);

	int T;
	input >> T;
	for (CaseNum = 1; CaseNum <= T; ++CaseNum)
	{
		SolveInstance();
	}

	return 0;
}

bool IsConsistent(int** lawn, int N, int M, int x, int y);

void SolveInstance()
{
	int N, M;
	input >> N >> M;


	int** lawn = new int*[N];
	for (int i = 0; i < N; ++i)
	{
		lawn[i] = new int[M];
		for (int j = 0; j < M; ++j)
		{
			input >> lawn[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!IsConsistent(lawn, N, M, i, j))
			{
				output << "Case #" << CaseNum << ": NO" << endl;
				return;
			}
		}
	}

	output << "Case #" << CaseNum << ": YES" << endl;
}

bool IsConsistent(int** lawn, int N, int M, int x, int y)
{
	int refHeight = lawn[x][y];

	//Check one way
	bool consistent = true;
	for (int i = 0; i < M; ++i)
	{
		if(lawn[x][i] > refHeight)
		{
			consistent = false;
			break;
		}
	}
	if(consistent)
		return true;

	//Check the other way
	consistent = true;
	for (int i = 0; i < N; ++i)
	{
		if(lawn[i][y] > refHeight)
		{
			consistent = false;
			break;
		}
	}
	if(consistent)
		return true;

	return false;
}