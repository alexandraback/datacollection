#include<cstdio>
int i,j,T,N,S,P,Ans,p,A;
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for(j=1;j<=T;++j)
	{
		scanf("%d%d%d",&N,&S,&P);
		Ans=0;
		for(i=1;i<=N;++i)
		{
			scanf("%d",&A);
			p=A/3;
			if(A>p*3) ++p;
			if(p>=P) ++Ans;
			else if(A%3!=1&&A!=0&&S>0&&p+1>=P) ++Ans,--S;
		}
		printf("Case #%d: %d\n",j,Ans);
	}
	return 0;
}
