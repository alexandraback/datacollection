#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdio.h>
#define ZERO(X) memset(X,0,sizeof(X))
#define FOR(I,N) for (I=0;I<(N);++I)
#define REV(I,N) for (I=(N)-1;I>=0;--I)
#define FORK(I,K,N) for (I=(K);I<(N);++I)
#define REVK(I,K,N) for (I=(K);I>=0;--I)
#define pb push_back
#define sci(d) scanf("%d",&d)
#define scll(l) scanf("%lld",&l)
#define scull(l) scanf("%llu",&l)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int v[11111],n,e,r;

void stupid (int pos, int ce, ull gain, ull & ans)
{
	ans=max(ans,gain);
	if (pos>=n) return;
	int i;
	for (i=0;i<=ce;++i)
		stupid(pos+1,min(ce-i+r,e),gain+((ull)i)*((ull)v[pos]),ans);
}

int main ()
{
	int j,t;
	sci(t);
	FOR(j,t)
	{
		int i;
		scanf("%d %d %d",&e,&r,&n);
		FOR(i,n) sci(v[i]);
		ull ans=0;
		/*if (r>=e)
		{
			FOR(i,n) ans+=(ull)e*((ull)v[i]);
		}
		else
		{
			int mx=0;
			FOR(i,n) ans+=(ull)r*((ull)v[i]),mx=max(mx,v[i]);
			e-=r;
			ans+=(ull)e*((ull)mx);
		}*/
		stupid(0,e,0,ans);
		printf("Case #%d: %lld\n",j+1,ans);
	}
	return 0;
}