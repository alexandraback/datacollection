#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	int t; cin >> t;
	for(int ss=1;ss<=t;ss++)
	{
		printf("Case #%d: ",ss);
		int n;
		int pos,num,sp;
		cin >> n;
		P p[10]; int nx=0;
		for(int i=0;i<n;i++)
		{
			cin >> pos >> num >> sp;
			for(int j=0;j<num;j++)
			{
				p[nx+j] = mp(pos,sp+j);
			}
			nx+=num;
		}
		sort(p,p+nx);
		int res = INF;
		for(int i=0;i<(1<<nx);i++)
		{
			for(int j=0;j<nx;j++)
			{
				if(((i>>j)&1)) continue;
				for(int k=0;k<j;k++)
				{
					if(p[k].sc < p[j].sc)
					{
						ll t0;
						if(!((i>>k)&1)) t0=1LL*(720-p[k].fi) * p[k].sc;
						else t0=1LL*(1080-p[k].fi) * p[k].sc;
						ll t1 = 1LL*(360-p[j].fi) * p[j].sc;
						if(t0<=t1) goto FAIL;
					}
				}
				for(int k=j+1;k<nx;k++)
				{
					if(p[k].sc < p[j].sc)
					{
						ll t0;
						if(!((i>>k)&1)) t0=1LL*(720-p[k].fi) * p[k].sc;
						else t0=1LL*(1080-p[k].fi) * p[k].sc;
						ll t1 = 1LL*(360-p[j].fi) * p[j].sc;
						if(t0<=t1) goto FAIL;
					}
				}
			}
			res = min(res,__builtin_popcount(i));
			FAIL:;
		}
		cout << res << endl;
	}
}