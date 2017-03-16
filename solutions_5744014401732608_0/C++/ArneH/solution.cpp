#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void printSolution(unsigned int T, const vector<vector<int>>& sol, bool possible)
{
	cout << "Case #" << T << ": ";
	if (possible)
	{
		cout << "POSSIBLE" << endl;
		for (int i = 0; i < sol.size(); ++i)
		{
			for (int j = 0; j < sol.size(); ++j)
			{
				cout << sol[i][j];
			}
			cout << endl;
		}
	}
	else
	{
		cout << "IMPOSSIBLE" << endl;
	}
}

void buildFramework(vector<vector<int>>& sol, int B)
{
	for (int i = 1; i < B-1; ++i)
	{
		for (int j = 0; j < i; ++j )
		{
			sol[B-i-1][B-j-1] = 1;
		}
	}
}

bool isPossible(long long int M, int B)
{
	if ( M == 0)
		return true;
	long long int p = 1;
	for (int i = 0; i < B-2; ++i)
	{
		if (M < p)
			return true;
		p *= 2;
	}
	return false;
}

void solve(unsigned int T)
{
	int B;				// Number of buildings
	long long int M;				// Age of Gooli
	bool possible = false;

	cin >> B >> M;
	M--;
	vector<vector<int>> solution( B, vector<int>(B,0));

	if (!isPossible(M, B))
		possible = false;
	else
	{
		possible = true;
		buildFramework(solution, B);
		solution[0][B-1] = 1;
		for (int i = 1; i < B-1; ++i)
		{
			if (M&1<<(i-1)) 
				solution[0][B-1-i] = 1;
		}

	}

	printSolution(T,solution, possible);	
}

int main( int argc, char** argv )
{
	int T;
	cin >> T;

	for ( int i = 1; i <= T; ++i ) solve(i);
	return 0;
}
