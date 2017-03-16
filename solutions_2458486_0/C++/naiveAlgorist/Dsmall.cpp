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
int init[205];
int N, K;
int Ti[20];
int Ki[20][205];

vector <int> ans;
int poss[1<<20];

void preprocess()
{
	
}

int f(int bm)
{
	if(bm == (1<<N) - 1)
		return 1;
	
	if(poss[bm] >= 0)
		return poss[bm];
	
	int val[205];
	for(int i = 0; i <= 200; i++)
		val[i] = init[i];
	for(int j = 0; j < N; j++)
		if(bm & (1<< j))
		{
			val[Ti[j]]--;
			for(int i = 0; i <= 200; i++)
				val[i] += Ki[j][i];
		}
	
	for(int i = 0; i < N; i++)
		if((bm & (1<<i)) == 0)
		{
			if(val[Ti[i]] > 0)
				if(f(bm | (1<<i)))
					return poss[bm] = 1;
		}
	return poss[bm] = 0;
}

bool input()
{
	fill(init, 0);
	s(K); s(N);
	for(int i = 0; i < K; i++)
	{
		int x;
		s(x);
		init[x]++;
	}
	
	fill(Ki, 0);
	for(int i = 0; i < N; i++)
	{
		int ki;
		s(Ti[i]);
		s(ki);
		for(int j = 0; j < ki; j++)
		{
			int x;
			s(x);
			Ki[i][x]++;
		}
	}
	
	
//	for(int i = 0; i < N; i++)
//	{
//		for(int j = 1; j <= 5; j++)
//			cerr << Ki[i][j] << " ";
//		cerr << endl;
//	}
	
	return true;
}

void solve()
{
	fill(poss, -1);
//	cerr << f(3) << endl;
	if(f(0) == 0)
	{	
		printf("IMPOSSIBLE\n");
		return;
	}
	
	int val[205];
	for(int i = 0; i <= 200; i++)
		val[i] = init[i];
	int bm = 0;
	while(bm != (1<<N) - 1)
	{
		for(int i = 0; i < N; i++)
		{
//			cerr << f(bm | (1<<i)) << endl;
			if(((bm & (1<<i)) == 0) && (val[Ti[i]] > 0) && (f(bm | (1<<i)) == 1))
			{
				printf("%d ", 1+i);
				bm |= 1<<i;
				val[Ti[i]]--;
				for(int j = 0; j <= 200; j++)
					val[j] += Ki[i][j];
//				cerr << bm << endl;
//				cerr << f(bm) << endl;
				break;
			}
		}
	}
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
