#include<cstdio>
#include<cstring>
int T,Case,i,j,k,len,Cnt,N;
int res1[100],res2[100],Res[100],A[100][100],B[100],g[300],h[300];
int f[3000000];
bool Renew(int x,int y,int z)
{
	int i;
	len=0;
	res1[++len]=z;
	for(i=x;i!=1;i-=1<<f[i])
		res1[++len]=f[i];
	len=0;
	for(i=y;i!=1;i-=1<<f[i])
		res2[++len]=f[i];
	for(i=len;i;--i)
	{
		if(res1[i]<res2[i]) return 1;
		if(res1[i]>res2[i]) return 0;
	}
}
int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	for(scanf("%d",&T);T--;)
	{
		++Case;
		scanf("%d%d",&A[0][0],&N);
		for(i=1;i<=A[0][0];++i) scanf("%d",&A[0][i]);
		for(i=1;i<=N;++i)
		{
			scanf("%d",&B[i]);
			scanf("%d",&A[i][0]);
			for(j=1;j<=A[i][0];++j) scanf("%d",&A[i][j]);
		}
		memset(f,-1,sizeof(f));
		f[1]=0;
		for(i=1;i<1<<(N+1);++i)
		{
			if(f[i]!=-1)
			{
				++Cnt;
				for(j=0;j<=N;++j)
					if(i&(1<<j))
					{
						for(k=1;k<=A[j][0];++k)
						{
							if(h[A[j][k]]!=Cnt)
								h[A[j][k]]=Cnt,g[A[j][k]]=0;
							++g[A[j][k]];
						}
						if(j>0)
						{
							if(h[B[j]]!=Cnt)
									h[B[j]]=Cnt,g[B[j]]=0;
							--g[B[j]];
						}
					}
				for(j=0;j<=N;++j)
					if(!(i&(1<<j))&&h[B[j]]==Cnt&&g[B[j]])
					{
						if(f[i+(1<<j)]==-1) f[i+(1<<j)]=j;
						else if(Renew(i,i+(1<<j),j)) f[i+(1<<j)]=j;
					}
			}
		}
		printf("Case #%d:",Case);
		if(f[(1<<(N+1))-1]==-1) printf(" IMPOSSIBLE\n");
		else
		{
			len=0;
			for(i=(1<<(N+1))-1;i!=1;i-=1<<f[i])
				Res[++len]=f[i];
			for(i=len;i;--i) printf(" %d",Res[i]);
			printf("\n");
		}
	}
	return 0;
}
