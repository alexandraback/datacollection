#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

typedef pair<int, int> ii;

int N;
double naomi[1000];
double ken[1000];

int war()
{
	int nEnd = N-1;
	int kEnd = N-1;
	int points = 0;

	//////////
	for (int i = 0; i < N; i++)
	{
		if (naomi[nEnd] < ken[kEnd])
			kEnd--;
		else
			points++;
		nEnd--;
	}
	//////////

	return points;
}

int dWar()
{
	bool visited[1001];
	for (int i = 0; i <= N; i++)
		visited[i] = false;
	int points = 0;
	////////
	for (int i = 0; i < N; i++)
	{
		double* upper = upper_bound(naomi, naomi+N, ken[i]);
		int j = distance(naomi, upper);
		while (j<=N && visited[j]) j++;
		if (j<N) {
			points++;
			visited[j] = true;
		} else {
		}
	}
	////////
	return points;
}

inline ii solve()
{
	ii solution;
	solution.first = dWar();
	solution.second = war();
	return solution;
}

int main()
{
	int T; cin >> T;
	double temp;
	for (int caseNum = 1; caseNum <= T; caseNum++)
	{
		// Get blocks
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> naomi[i];
		for (int i = 0; i < N; i++)
			cin >> ken[i];
		sort(naomi, naomi+N);
		sort(ken, ken+N);
		// Solve
		ii solution = solve();
		// Output solution
		printf("Case #%i: %i %i\n", caseNum, solution.first, solution.second);		
	}
	return 0;
}
