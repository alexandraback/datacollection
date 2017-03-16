//azariamuh

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

int inf = 1000000000;
typedef long long LL;

#define forn(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define reset(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()

int T,n,d[10],h[10],m[10];
vector<pair<int,int> > orang;

int main()
{
	scanf("%d",&T);
	forn(cases,1,T)
	{
		printf("Case #%d: ",cases);
		scanf("%d",&n);
		orang.clear();
		forn(i,0,n-1)
		{
			scanf("%d %d %d",&d[i],&h[i],&m[i]);
			forn(j,0,h[i]-1)
				orang.pb(mp(m[i] + j,d[i]));
		}
		sort(orang.begin(),orang.end());
		double tfast = ((double)(360 - orang[0].se) / 360.0 + 1.0) * orang[0].fi;
		double tslow = ((double)(360 - orang[1].se) / 360.0) * orang[1].fi;
		if (tslow >= tfast)
		{
			puts("1");
		} else 
		{
			puts("0");
		}
	}
	return 0;
}













