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
int X, Y;

void preprocess()
{
	
}

bool input()
{
	s(X); s(Y);
	return true;
}

void solve()
{
	for(int i = 0; i < X; i++)
		printf("WE");
	for(int i = 0; i > X; i--)
		printf("EW");
	for(int i = 0; i < Y; i++)
		printf("SN");
	for(int i = 0; i > Y; i--)
		printf("NS");
	printf("\n");
}

int main()
{
	preprocess();
	s(totalCases);
	for(testNum = 1; testNum <= totalCases; testNum++)
	{
		if( !input())
			break;
		printf("Case #%d: ", testNum);
		solve();
	}
}
