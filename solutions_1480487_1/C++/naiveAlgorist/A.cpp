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
int S[205];

double X;

void preprocess()
{
	
}

bool input()
{
	s(N);
	for(int i = 0; i < N; i++)
		s(S[i]);
	return true;
}

void solve()
{
	X = 0.0;
	for(int i = 0; i < N; i++)
		X += S[i];
	
	double lo, hi, mid;
	double ans[205];
	for(int i = 0; i < N; i++)
	{
		lo = 0.0, hi = 1.0;
		while(hi - lo > 1e-8)
		{
			mid = (lo + hi)/2;
			double curval = S[i] + X*mid;
			
			double tot = 0.0;
			for(int j = 0; j < N; j++)
				tot += max(0.0, (curval - S[j])/X);
			
			if(tot > 1.0 + 1e-9)
				hi = mid;
			else 
				lo = mid;
		}
		ans[i] = (hi + lo)*50;
	}
	
	printf("Case #%d: ", testNum);
	for(int i = 0; i < N; i++)
		printf("%lf ", ans[i]);
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
		solve();
	}
}
