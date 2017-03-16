#include <stdio.h>
#include <string.h>
#define clr(a,b) memset(a,b,sizeof(a))
int ab[30][30];
int bc[30][30];
int ac[30][30];
int aa[30];
int bb[30];
int cc[30];
int main()
{
	int T;
	scanf("%d",&T);
	for(int cas = 1; cas <= T; cas++)
	{
		int a,b,c,p;
		scanf("%d%d%d%d",&a,&b,&c,&p);
		clr(ab,0);
		clr(bc,0);
		clr(ac,0);
		int tot = 0;
		for(int i = 1; i <= a; i++)
			for(int j = 1; j <= b; j++)
				for(int k = 1; k <= c; k++)
				{
					if(ab[i][j] < p && bc[j][k] < p && ac[i][k] < p)
					{
						aa[tot] = i;
						bb[tot] = j;
						cc[tot] = k;
						tot++;
						ab[i][j]++;
						bc[j][k]++;
						ac[i][k]++;
					}
				}
		printf("Case #%d: %d\n", cas,tot);
		for(int i = 0; i < tot; i++)
			printf("%d %d %d\n", aa[i],bb[i],cc[i]);
	}
}