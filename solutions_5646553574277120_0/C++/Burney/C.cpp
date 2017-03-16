#include<cstdio>
#include<cstdlib>
int T,C,D,V;
int VIS[101],M[5];
int main()
{
	freopen("C.txt","r",stdin);
	freopen("C1.txt","w",stdout);
	scanf("%d",&T);
	int kase=1;
	while(T--)
	{
		scanf("%d%d%d",&C,&D,&V);
		for(int i=0;i<D;i++)
		{
			scanf("%d",&M[i]);
		}
		VIS[0]=1;
		for(int i=1;i<=V;i++)VIS[i]=0;
		for(int j=0;j<D;j++)
		{
			for(int i=V;i>=0;i--)
			{
				if(!VIS[i])continue;
				for(int k=1;k<=C&&i+k*M[j]<=V;k++)
				{
					VIS[i+k*M[j]]=1;
				}
			}
		}
		int ans=0;
		for(int i=0;i<=V;i++)
		{
			if(VIS[i])continue;
			ans++;
//			printf("i=%d\n",i);
			for(int j=V;j>=0;j--)
			{
				if(!VIS[j])continue;
				for(int k=1;k<=C&&j+k*i<=V;k++)
				{
					VIS[j+k*i]=1;
				}
			}
		}
		printf("Case #%d: %d\n",kase++,ans);
	}
	return 0;
}
