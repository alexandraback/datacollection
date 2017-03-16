#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
#define NN 1009

struct Attact {
	int d,w,e,s;
	bool operator < (const Attact &b) const {
		return d < b.d;
	}
};

int solve(Attact at[], int n, int *h)
{
	int i,j,d,t=0;
	i=0;
	while (i<n)
	{
		d = at[i].d;
		j=i+1;
		while (j<n && at[j].d == at[i].d) j++;
		int k;
		for (k=i; k<j; k++)
		{
			int ii;
			for (ii=at[k].w; ii<=at[k].e; ii++) if (at[k].s > h[ii]) break;
			if (ii<=at[k].e) t++;
		}
		for (k=i; k<j; k++)
		{
			int ii;
			for (ii=at[k].w; ii<=at[k].e; ii++) {
				if (h[ii] < at[k].s) h[ii] = at[k].s;
			}
		}
		i=j;
	}
	return t;
}

int main()
{
	int t,N,i,ha[2000], *h;
	Attact tb[NN];
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("c-small.out", "w", stdout);

	scanf("%d",&t);
	for (int cas=1; cas<=t; cas++)
	{
		int n,dd,dp,ds;
		scanf("%d",&N);
		int j = N;
		for (i=0; i<N; i++) {
			scanf("%d%d%d%d%d", &(tb[i].d), &n, &(tb[i].w), &(tb[i].e), &(tb[i].s));
			scanf("%d%d%d", &dd, &dp, &ds);
			tb[i].w *= 2;
			tb[i].e *= 2;
			dp *= 2;
			for (int k=1; k<n; k++) {
				tb[j].d = tb[i].d + k*dd;
				tb[j].w = tb[i].w + k*dp;
				tb[j].e = tb[i].e + k*dp;
				tb[j].s = tb[i].s + k*ds;
				j++;
			}	
		}
		n = j;
		memset(ha, 0, sizeof(ha));
		h = ha+1000;
		sort(tb, tb+n);
		int times = solve(tb, n, h);
		printf("Case #%d: %d\n", cas, times);
	}
	return 0;
}

