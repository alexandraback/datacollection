/*
 	Team Proof
	IIT Delhi
 
	C++ Template
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

int totalCases, testNum;
int N;
int vals[25];

map <int, int> sums;

void preprocess()
{
	
}

bool input()
{
	s(N);
	for(int i = 0; i < N; i++)
		s(vals[i]);
	
	return true;
}

void output(int bm1, int bm2)
{
	int cm = bm1 & bm2;
	bm1 -= cm;
	bm2 -= cm;
	
	for(int i = 0; i < N; i++)
		if(bm1 & (1<<i))
			printf("%d ", vals[i]);
	printf("\n");

	for(int i = 0; i < N; i++)
		if(bm2 & (1<<i))
			printf("%d ", vals[i]);
	printf("\n");
}

void solve()
{
	sums.clear();
	
	printf("Case #%d:\n", testNum);
	for(int i = 1; i < (1<<20); i++)
	{
		int tot = 0;
		for(int j = 0; j < N; j++)
			if(i & (1<<j))
				tot += vals[j];
		
		if(sums.count(tot))
		{
			output(sums[tot], i);
			return;
		}
		sums[tot] = i;
	}
	printf("Impossible\n");
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
