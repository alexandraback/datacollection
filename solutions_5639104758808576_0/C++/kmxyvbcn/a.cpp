#include<cstdio>

char p[1100];

int main()
{
	int i,j,Ans,TestCase,Case,n;
//	freopen("a.in","rb",stdin);
//	freopen("a.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d%s",&n,p);
		for(Ans=j=i=0;i<=n;i++)
		{
			if(j<i){Ans+=i-j;j=i;}
			j+=p[i]-'0';
		}
		printf("Case #%d: %d\n",Case,Ans);
	}
	return 0;
}
