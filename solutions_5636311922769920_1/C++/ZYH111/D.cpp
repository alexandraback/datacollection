#include<cstdio>
#define LL long long
int main()
{
	LL i,j,K,C,S,M,N;
	int T,_T;
	bool flag;
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%d",&T);
	for (_T=1;_T<=T;_T++)
	{
		printf("Case #%d:",_T);
		scanf("%I64d%I64d%I64d",&K,&C,&S);
		if (C*S<K) printf(" IMPOSSIBLE\n");
		else
		{
			M=0; flag=true;
			for (i=1;i<=S;i++)
			{
				N=0;
				for (j=1;j<=C;j++)
				{
					N=N*K+M;
					if (M<K-1) M++;
					else flag=false;
				}
				printf(" %I64d ",N+1);
				if (!flag) break;
			}
			printf("\n");
		}
	}
	return 0;
}
