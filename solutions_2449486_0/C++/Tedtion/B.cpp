#include <stdio.h>
#include <string.h>
#define NN 108

bool can(int h[][NN], int n, int m)
{
	int i,j,hestn[NN],hestm[NN];
	memset(hestn, 0, sizeof(hestn));
	memset(hestm, 0, sizeof(hestm));
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++) {
			if (hestn[i] < h[i][j]) hestn[i] = h[i][j];
			if (hestm[j] < h[i][j]) hestm[j] = h[i][j];
		}
	}
	for (i=0; i<n; i++) for (j=0; j<m; j++)
	{
		if (h[i][j]<hestn[i] && h[i][j]<hestm[j]) return false;
	}
	return true;
}

int main()
{
	int t,n,m,h[NN][NN];
	int i,j;
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	scanf("%d",&t);
	for (int cas=1; cas<=t; cas++)
	{
		scanf("%d%d",&n,&m);
		for (i=0; i<n; i++) for (j=0; j<m; j++) scanf("%d",&h[i][j]);
		printf("Case #%d: ",cas);
		if (can(h,n,m)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

