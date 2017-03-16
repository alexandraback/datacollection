#define _CRT_SECURE_NO_DEPRECATE

#pragma comment(linker,"/STACK:260108864")

#include <iostream>
#include <ctime>
#include <cstdio>
#include <memory>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <utility>
#include <iterator>
#include <bitset>
#include <sstream>
#include <numeric>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define LL long long
#define ULL unsigned LL
#define VI vector<int>
#define X first
#define Y second
#define sz(_v) ((int)_v.size())
#define all(_v) (_v).begin(),(_v).end()
#define FOR(i,a,b) for (int i(a); i<=(b); ++i)
#define rep(i,a) FOR(i,1,a)
#define rept(i,a) FOR(i,0,(int)(a)-1)
#define x1 X1
#define y1 Y1
#define sqr(a) ((a)*(a))
#define C(a) memset((a),0,sizeof (a))
#define MS(a,x) memset((a),(x),sizeof (a))
#define INF 2000000000
#define PI 3.141592653589
#define eps 0.000000001
#define MOD 1000000007
#define PRIME 1000003

using namespace std;

VI d;

int main()
{
#ifndef ONLINE_JUDGE
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
#endif
	int tst;
	scanf("%d",&tst);
	rept(t,tst)
	{
		printf("Case #%d:\n",t+1);
		int n;
		scanf("%d",&n);
		d.resize(n);
		rept(i,n) scanf("%d",&d[i]);
		int upTo(1<<sz(d));
		VI sums;
		sums.reserve(upTo);
		rept(i,upTo)
		{
			int sm(0);
			rept(j,n)
			{
				if (i&(1<<j)) sm+=d[j];
			}
			sums.pb(sm);
		}
		bool solved(false);
		int maskres1,maskres2;
		rept(i,upTo)
		{
			for (int mask=i; mask; mask=(mask-1)&i)
			{
				int sum1(sums[mask]);
				int maskelse(i&(~mask));
				int sum2(sums[maskelse]);
				if (sum1==sum2)
				{
					solved=true;
					maskres1=mask;
					maskres2=maskelse;
					break;
				}
			}
			if (solved) break;
		}
		if (solved)
		{
			bool has(false);
			rept(i,n)
			{
				if (maskres1&(1<<i))
				{
					if (has) printf(" ");
					has=true;
					printf("%d",d[i]);
				}
			}
			printf("\n");
			has=false;
			rept(i,n)
			{
				if (maskres2&(1<<i))
				{
					if (has) printf(" ");
					has=true;
					printf("%d",d[i]);
				}
			}
			printf("\n");
		}
		else printf("Impossible\n");
	}
	return 0;
}