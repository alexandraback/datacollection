#include <stdio.h>

int x[5][5]={
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2,-1, 4,-3},
	{0, 3,-4,-1, 2},
	{0, 4, 3,-2,-1}};

char s[10001];

int main() {
	int i,j,T,tt;
	scanf("%d\n",&T);
	for (tt=1;tt<=T;tt++) {
		long long L,X;
		scanf("%lld %lld\n",&L,&X);
		scanf("%s\n",s);
		char *p;
		int m=1;
		int goti=0;
		int gotj=0;
		int gotk=0;
		for (j=0;j<X&&j<100;j++) {
			p=s;
			while (*p) {
				if (m<0) m=-x[-m][*p-'g'];
				else m=x[m][*p-'g'];
				if (!goti&&m==2) goti=1;
				if (goti&&!gotj&&m==4) gotj=1;
				p++;
			}
			if (!j) {
				int u=1;
				if (m<0) m=-x[u][-m];
				else m=x[u][m];
				u=1;
				int v=1;
				if (m<0) v=-1;
				for (i=0;i<X%4;i++)
					if (u<0) u=-v*x[-u][v*m];
					else u=v*x[u][v*m];
				if (u==-1) gotk=1;
			}
		}
		printf("Case #%d: %s\n",tt,goti&&gotj&&gotk?"YES":"NO");
	}
	return 0;
}
