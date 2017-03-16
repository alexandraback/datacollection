#include <stdio.h>

int max(int a,int b){if(a>b)return a;return b;}
int min(int a,int b){if(a<b)return a;return b;}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	
	int T,z=0;
	scanf("%d",&T);

	while (++z<=T)
	{
		int E,R,N,V[10010];

		int i,j,k;
		scanf("%d%d%d",&E,&R,&N);
		for (i=1; i<=N; i++)
			scanf("%d",V+i);

		int D[11][6]={0};

		for (i=1; i<=N; i++) {
			for (j=1; j<=E; j++) {
				for (k=0; k<=j; k++) {
					int e = D[i-1][k] + min(j,j-k+R)*V[i];
					D[i][j] = max(D[i][j],e);


				}
			}
		}
		int ret = 0;
		for (i=0; i<=E; i++)
			ret = max(ret,D[N][i]);
		printf("Case #%d: %d\n",z,ret);
	}
}
/*

		4	1	3	5
0	0	0	0		
1	1	4			
2	2	8			
3	3	12		




*/
