#include <cstdio>
#include <cstring>
int map[101][101];
int maxl[101],maxr[101];
int T,N,M;
int main()
{
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		int i,j;
		scanf("%d%d",&N,&M);
		memset(maxl,0,sizeof(maxl));
		memset(maxr,0,sizeof(maxr));
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
			{
				scanf("%d",&map[i][j]);
				if (map[i][j]>maxl[i])
					maxl[i]=map[i][j];
				if (map[i][j]>maxr[j])
					maxr[j]=map[i][j];
			}
		int ANS=1;
		for (i=1;i<=N && ANS;i++)
			for (j=1;j<=M && ANS;j++)
				if (map[i][j]<maxl[i] && map[i][j]<maxr[j])
					ANS=0;
		printf("Case #%d: ",TT);
		if (ANS)
			printf("YES\n");
		else 
			printf("NO\n");
	}
}
