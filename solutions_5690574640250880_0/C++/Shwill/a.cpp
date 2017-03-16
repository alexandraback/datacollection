#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

typedef vector<int> vi;

char grid[2500];
int R, C, M, B, size;

/////// ADJ Helpers
vi adjs;
inline void getAdjs(int ind)
{
	adjs.clear();
	int i = ind%C;
	int j = ind/C;
	// Up
	if (j>0) {
		adjs.push_back(ind-C);
		if (i>0)
			adjs.push_back(ind-1-C);
		if (i+1 < C)
			adjs.push_back(ind-C+1);
	}
	// Down
	if (j+1 < R) {
		adjs.push_back(ind+C);
		if (i>0)
			adjs.push_back(ind+C-1);
		if (i+1 < C)
			adjs.push_back(ind+C+1);
	}
	// Sides
	if (i>0)
		adjs.push_back(ind-1);
	if (i+1<C)
		adjs.push_back(ind+1);
}

inline bool goodAdjs()
{
	for (vi::iterator it = adjs.begin(); it != adjs.end(); it++)
		if (grid[*it] == '*')
			return false;	
	return true;
}
///////////////////


inline void printGrid()
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		cout << grid[i];
		counter++;
		if (counter == C) {
			cout << '\n';
			counter = 0;
		}
	}
}


inline bool isValid()
{
	int start;
	for (int i = size-1; i >= 0; i--)
		if (grid[i] == 'c') {
			start = i;
			break;
		}
	getAdjs(start);
	if (!goodAdjs()) {
		return (1 == B);
	}
	//////////
	stack<int> Q; Q.push(start);
	vector<bool> S(size, false); S[start] = true;
	int v;
	int numVisited = 0;
	////// DFS
	while (Q.size()) {
		v = Q.top(); Q.pop();
		numVisited++;
		getAdjs(v);
		if (!goodAdjs())
			continue;
		for (vi::iterator it = adjs.begin(); it != adjs.end(); it++) {
			if (!S[*it]) {
				S[*it] = true;
				Q.push(*it);
			}
		}
	}
	//////////
	return numVisited == B;
}

int main()
{
	adjs.reserve(8);
	int T; cin >> T;
	for (int caseNum = 1; caseNum <= T; caseNum++)
	{
		// Get information
		cin >> R >> C >> M;
		size = R * C;
		B = size - M;
		// Setup grid
		int i;
		for (i = 0; i < M; i++)
			grid[i] = '*';
		for (; i < size; i++)
			grid[i] = '.';
		grid[size-1] = 'c';
		// Test until solved
		bool good = true;
		while (good && !isValid()) {
			good = next_permutation(grid, grid+size);
		}
		///////////////////////
		printf("Case #%i:\n", caseNum);
		if (good)
			printGrid();
		else
			printf("Impossible\n");
	}
	return 0;
}
