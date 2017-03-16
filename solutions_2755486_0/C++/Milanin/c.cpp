#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
#define N 1000
#define K 1000010
int mm[2*N+1], *m=mm+N;
struct T
{
	int l, r, s, t;
	T(int l=0, int r=0, int s=0, int t=0): l(l), r(r), s(s), t(t) {}
};
bool operator <(T a, T b) { return a.t<b.t; }
T t[K];
int main()
{
	int ts, tst;
	int n, x, r, i, k;
	int ft, j, x1, x2, s, dd, dp, ds;
	for(scanf("%d", &tst), ts=1; ts<=tst; ts++)
	{
		printf("Case #%d: ", ts);
		for(x=-N; x<=N; m[x]=0, x++);
		for(n=0, scanf("%d", &k); k--; )
			for(scanf("%d%d%d%d%d%d%d%d", &ft, &j, &x1, &x2, &s, &dd, &dp, &ds); j--; t[n++]=T(x1, x2, s, ft), ft+=dd, x1+=dp, x2+=dp, s+=ds);
		sort(t, t+n);
		for(r=0, i=0; i<n; )
		{
			dd=i;
			for(ft=t[i].t; i<n && t[i].t==ft; r+=k, i++)
				for(k=0, j=t[i].l; j<t[i].r; k|=m[j]<t[i].s, j++);
			i=dd;
			for(ft=t[i].t; i<n && t[i].t==ft; i++)
				for(j=t[i].l; j<t[i].r; m[j]=max(m[j], t[i].s), j++);
		}
		printf("%d\n", r);
	}
	return 0;
}