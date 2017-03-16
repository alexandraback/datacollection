#include<cstdio>
#include<cstring>
int T,Case,i,j,Ans,s,Max,p,flag,N;
int A[1005],B[1005],f[1005],g[1005];
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for(Case=1;Case<=T;++Case)
	{
		scanf("%d",&N);
		for(i=1;i<=N;++i) scanf("%d%d",&A[i],&B[i]);
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		s=0,Ans=0;
		for(;s<2*N;)
		{
			flag=0;
			for(j=1;j<=N;++j)
				if(!g[j]&&!f[j]&&B[j]<=s)
				{
					s+=2;
					++Ans;
					g[j]=f[j]=1;
					flag=1;
					break;
				}
			if(flag) continue;
			for(j=1;j<=N;++j)
				if(!g[j]&&B[j]<=s)
				{
					++s;
					++Ans;
					g[j]=1;
					flag=1;
					break;
				}
			if(flag) continue;
			Max=p=0;
			if(!flag)
				for(j=1;j<=N;++j)
					if(!f[j]&&A[j]<=s&&B[j]>Max)
						Max=B[j],p=j;
			if(p!=0)
			{
				++s;
				++Ans;
				f[p]=1;
				flag=1;
			}
			if(!flag) break;
		}
		if(!flag) printf("Case #%d: Too Bad\n",Case);
		else printf("Case #%d: %d\n",Case,Ans);
	}
	return 0;
}
