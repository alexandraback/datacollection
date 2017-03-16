#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <cstdio>

using namespace std;

vector<vector<bool> > routes;
vector<string> zips;
int N, M;

void dfs(vector<int>& permutation, int fromI, int& toI)
{
	while (true)
	{
		if (toI == permutation.size())
			return;

		int from = permutation[fromI];
		int to = permutation[toI];

		if (routes[from][to])
		{
			toI++;
			dfs(permutation, toI-1, toI);
			continue;
		}
		break;
	}
}

void solveCase(int t)
{
	cin >> N >> M;
	zips = vector<string>(N);

	for (int i = 0; i < N; ++i)
		cin >> zips[i];

	routes = vector<vector<bool> >(N, vector<bool>(N, false));

	for (int i = 0; i < M; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;
		n1--; n2--;
		routes[n1][n2] = true;
		routes[n2][n1] = true;
	}

	vector<int> permutation(N);
	for (int i = 0; i < N; ++i)
		permutation[i] = i;

	vector<string> solutions;
	do 
	{
		vector<bool> visited(N, false);
		int to = 1;
		dfs(permutation, 0, to);
		if (to == N)
		{
			string s;
			for (int i = 0; i < N; ++i)
			{
				s += zips[permutation[i]];
			}
			solutions.push_back(s);
		}

	} while (next_permutation(permutation.begin(),permutation.end()));
	sort(solutions.begin(), solutions.end());
	cout << solutions[0];
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{	
		cout << "Case #" << t << ": ";
        solveCase(t);
        cout << endl;
	}
	
	return 0;
}