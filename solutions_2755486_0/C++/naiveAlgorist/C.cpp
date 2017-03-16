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

const int maxn = 15;
const int maxd = 676065;

int totalCases, testNum;
int N;

int d[maxn];
int n[maxn];
int w[maxn];
int e[maxn];
int S[maxn];
int deltaD[maxn];
int deltaP[maxn];
int deltaS[maxn];

int curd[maxn];
int curn[maxn];
int curw[maxn];
int cure[maxn];
int curS[maxn];

int height [1000];
int offset;

void preprocess()
{
	fill(height, 0);
	offset = 500;
}

bool input()
{
	s(N);
	for(int i = 0; i < N; i++)
	{
		s(d[i]);
		s(n[i]);
		s(w[i]);
		s(e[i]);
		s(S[i]);
		s(deltaD[i]);
		s(deltaP[i]);
		s(deltaS[i]);
	}
	return true;
}

void init()
{
	for(int i = 0; i < N; i++)
	{
		curd[i] = d[i];
		curn[i] = 0;
		curw[i] = 2*w[i] + offset;
		cure[i] = 2*e[i] + offset;
		curS[i] = S[i];
	}
}

void solve()
{
	init();
	fill(height, 0);
	int ans = 0;
	
	int now;
	do 
	{
		now = maxd;
		for(int i = 0; i < N; i++)
			now = min(now, curd[i]);
		if(now == maxd)
			break;
		
		for(int i = 0; i < N; i++)
		{
			if(curd[i] == now)
			{
				bool success = false;
				for(int j = curw[i]; j <= cure[i]; j++)
					if(height[j] < curS[i])
					{
						success = true;
						break;
					}
				
				//fprintf(stderr, "Tribe %d hits on day %d at height %d in the interval [%d, %d] with success = %d\n", i+1, now, curS[i], curw[i]-offset, cure[i]-offset, success);
				
				if(success)
					ans++;
			}
		}
		
		for(int i = 0; i < N; i++)
		{
			if(curd[i] == now)
			{
				for(int j = curw[i]; j <= cure[i]; j++)
					height[j] = max(height[j], curS[i]);
				
				curn[i]++;
				if(curn[i] == n[i])
					curd[i] = maxd;
				else 
					curd[i] += deltaD[i];
				
				curS[i] += deltaS[i];
				curw[i] += 2*deltaP[i];
				cure[i] += 2*deltaP[i];
			}
		}
	}while(now < maxd);
	printf("%d\n", ans);
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
