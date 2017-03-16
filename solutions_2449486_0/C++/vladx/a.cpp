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
typedef struct
{
	int h,i,j;
} grass;

bool operator< (const grass & a, const grass & b){return a.h<b.h;}

inline grass mkg (int h, int i, int j)
{
	grass g={h,i,j};
	return g;
}

int a[101][101],n,m;
grass g[10011];

bool higher (grass c)
{
	int i,k=0;
	for (i=c.i-1;i>=0;--i) if (a[i][c.j]>c.h) ++k;
	for (i=c.i+1;i<n;++i) if (a[i][c.j]>c.h) ++k;
	if (k==0) return false;
	k=0;
	for (i=c.j-1;i>=0;--i) if (a[c.i][i]>c.h) ++k;
	for (i=c.j+1;i<m;++i) if (a[c.i][i]>c.h) ++k;
	if (k==0) return false;
	return true;
}

void solve ()
{
	int i,j,k=0;
	FOR(i,n) FOR(j,m) g[k]=mkg(a[i][j],i,j),++k;
	sort(g,g+k);
	--k;
	while (k>=0)
	{
		if (higher(g[k]))
		{
			puts("NO");
			return;
		}
		--k;
	}
	puts("YES");
}

int main ()
{
	int t,i;
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&t);
	FOR(i,t)
	{
		int j,k;
		scanf("%d %d",&n,&m);
		FOR(j,n) FOR(k,m) scanf("%d",&a[j][k]);
		printf("Case #%d: ",i+1);
		solve();
	}
	return 0;
}