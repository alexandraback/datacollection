/*
 	C++ Template
	Pradeep George Mathias
 */


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
using namespace std;

#define s(T) scanf("%d", &T)
#define sl(T) scanf("%lld", &T)
#define fill(a, val) memset(a, val, sizeof(a))
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define DREP(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define INDEX(a, val) (lower_bound(all(a), val) - a.begin())

int totalCases, testNum;
int N,M;
int a[105][105];

void preprocess()
{
	
}

bool input()
{
	s(N);
	s(M);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			s(a[i][j]);
	return true;
}

bool checkrow(int r, int c)
{
	bool good = true;
	for(int i = 0; i < M; i++)
		if(a[r][i] > a[r][c])
			good = false;
	return good;
}

bool checkcol(int r, int c)
{
	bool good = true;
	for(int i = 0; i < N; i++)
		if(a[i][c] > a[r][c])
			good = false;
	return good;
}

void solve()
{
	bool good = true;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			good = good && (checkcol(i, j) || checkrow(i, j));
	if(good)
		printf("Case #%d: YES\n", testNum);
	else 
		printf("Case #%d: NO\n", testNum);
}

int main()
{
	preprocess();
	s(totalCases);
	for(testNum = 1; testNum <= totalCases; testNum++)
	{
		if( !input())
			break;
		solve();
	}
}
