#include<cstdio>
int n,K,C,S;
int main()
{
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int casei=1;casei<=n;casei++)
	{
		scanf("%d%d%d",&K,&C,&S);
		printf("Case #%d:",casei);
		if(C==1)
			if(S<K)
				printf(" IMPOSSIBLE",casei);
			else
				for(int i=1;i<=K;i++)
					printf(" %d",i);
		else if(S<(K+1)/2)
			printf(" IMPOSSIBLE",casei);
		else
			for(int i=0;i<(K+1)/2;i++)
				printf(" %d",i*K+K-i);
		printf("\n");
	}
}
