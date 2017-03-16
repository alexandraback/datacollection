#include <cstdio>
#include <cstring>
int g[55][55];
int main()
{
	int T,b;
	long long m;
	scanf("%d",&T);
	for(int cases=1;cases<=T;cases++)
	{
		scanf("%d%lld",&b,&m);
		printf("Case #%d: ",cases);
		if(m>(1LL<<(b-2)) )
		{
			puts("IMPOSSIBLE");
			continue;
		}
		memset(g,0,sizeof(g));
		for(int i=0;i<b-1;i++)
			for(int j=i+1;j<b-1;j++)
				g[i][j]=1;
		int t=1;
		if(m==(1LL<<(b-2))) g[0][b-1]=1,m--;
		while(m)
		{
			if(m&1)
				g[t][b-1]=1;
			m>>=1;
			t++;
		}
		puts("POSSIBLE");
		for(int i=0;i<b;i++,puts(""))
			for(int j=0;j<b;j++)
				printf("%d",g[i][j]);
	}
	return 0;
}
