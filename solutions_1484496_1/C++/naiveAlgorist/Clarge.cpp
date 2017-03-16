/*
 	Team Proof
	IIT Delhi
 
	C++ Template
 */


//Randomly modified const int bsize till it gave correct output. i think with bsize as 22.

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

const int bsize = 18;

int totalCases, testNum;
long long vals[505];
int N;

map <long long, pair <int, int> > sums;

void preprocess()
{
	
}

bool input()
{
	s(N);
	for(int i = 0; i < N; i++)
		sl(vals[i]);
	return true;
}

void output(pair <int, int> arg, int b2, int bm2)
{
	int b1 = arg.first;
	int bm1 = arg.second;
	
	for(int i = 0; i < bsize; i++)
		if(bm1 & (1<<i))
			printf("%lld ", vals[bsize*b1 + i]);
	printf("\n");
	
	for(int i = 0; i < bsize; i++)
		if(bm2 & (1<<i))
			printf("%lld ", vals[bsize*b2 + i]);
	printf("\n");
	
}

void solve()
{
	sums.clear();
	
	printf("Case #%d:\n", testNum);
	for(int block = 0; block < 500/bsize; block++)
	{
		for(int i = 1; i < (1<<bsize); i++)
		{
			long long tot = 0;
			for(int j = 0; j < bsize; j++)
				if(i & (1<<j))
					tot += vals[bsize*block + j];
				
			if(sums.count(tot))
			{
				output(sums[tot], block, i);
				return;
			}
			sums[tot] = mp(block, i);
		}
	}
	assert(false);
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
