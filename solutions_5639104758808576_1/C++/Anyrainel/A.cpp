#include <cstdio>
#include <cctype>
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout); 
	int T,sm,tot,ans;
	char s;
	scanf("%d",&T);
	for(int j=1;j<=T;j++)
	{
		scanf("%d",&sm);
		sm++;tot=0;ans=0;
		for(int i=1;i<=sm;i++)
		{
			while(!isdigit(s=getchar()));
			tot+=s-'0';
			if(i-tot>ans) ans=i-tot;
		}
		printf("Case #%d: %d\n",j,ans);
	}
	return 0;
}
