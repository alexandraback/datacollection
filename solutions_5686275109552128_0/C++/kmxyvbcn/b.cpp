#include<cstdio>

int n,p[1100],Ans,Now,Max,K,TestCase,Case;

int main()
{
	int i;
	//freopen("b.in","rb",stdin);
	//freopen("b.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d",&n);
		for(Max=i=0;i<n;i++)
		{
			scanf("%d",p+i);
			if(p[i]>Max)
				Max=p[i];
		}
		Ans=Max;
		for(K=1;K<=Max;K++)
		{
			Now=0;
			for(i=0;i<n;i++)
				if(p[i]>K)
					Now+=(p[i]+K-1)/K-1;
			if(Ans>Now+K)
				Ans=Now+K;
		}
		printf("Case #%d: %d\n",Case,Ans);
	}
	return 0;
}
