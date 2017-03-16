#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cassert>
#define CLRM(x) memset(x,-1,sizeof(x))
#define CLR(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(),x.end()
#define GI(x) scanf("%d", &x);
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FOR(i, start, end) for(int i = start; i < end; i++)
#define PB push_back
#define MP make_pair
#define VI vector<int> 
#define VVI vector<vector<int> >
#define PII pair<int,int>
#define SZ(x) (int)x.size()
#define LL long long
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
#define LMAX 1000000000000000000LL
#define IMAX 1000000000
using namespace std;

#define MAXN 1100
int v[1100];
int N;

double getlim()
{
	int total = 0;
	int maxv = 0;
	FORN(i, N)
	{
		maxv = MAX(maxv, v[i]);
		total += v[i];
	}
	int done = 0;
	FORN(i, N)
	{
		done += (maxv - v[i]);
	}
	int left = total - done;
	if(left > 0)	
		return (double)left/(double)N + maxv;
	double lo = 0, hi = total;
	int iterations = 0;
	while(lo < hi && iterations < 100000)
	{
		iterations++;
		double mid = (lo+hi)/2;
		double tot = 0;
		FORN(i, N)
		{
			if(v[i] - mid < -1e-6)
			{
				tot += (mid - v[i]);
			}
		}
		if(tot - total < -1e-6)
			lo = mid;
		else
			hi = mid;
	}
	//cout<<lo<<endl;
	return lo;
}
vector<double> solve() 
{
	double lim = getlim();
	//cout<<lim<<endl;
	vector<double> ret;
	int total = 0;
	FORN(i, N)
	{
		total += v[i];
	}
	FORN(i, N)
	{
		double val = 0;
		if(lim > v[i])
			val = (lim - v[i])*100.0/total;
		
		ret.PB(val);
	}
	return ret;
}
int main()
{
	int tes;
	GI(tes);
	for(int c = 1; c <= tes; c++)
	{
		GI(N);
		for(int i = 0; i < N; i++)
		{
			GI(v[i]);
		}
		vector<double> ans = solve();
		printf("Case #%d: ", c);
		for(int i = 0; i < ans.size(); i++)
		{
			printf("%.6f ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
