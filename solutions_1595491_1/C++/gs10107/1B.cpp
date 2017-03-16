#include <stdio.h>
int ti[101];
int che[101];
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("output.out","w",stdout);
	int i,z,t,n,s,p,ans,ch;
	scanf("%d",&t);
	for(z=1;z<=t;z++)
	{
		ans=0;
		printf("Case #%d: ",z);
		scanf("%d",&n);
		scanf("%d",&s);
		scanf("%d",&p);
		for(i=1;i<=n;i++)
		{
			che[i]=0;
			scanf("%d",&ti[i]);
		}
		for(i=1;i<=n;i++)
		{
			if(ti[i]%3==0)
			{
				ch=ti[i]/3;
			}
			else 
			{
				ch=(ti[i]/3)+1;
			}
			if(ch>=p)
			{
				che[i]=1;
				ans++;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(che[i]==0 && s!=0 && ti[i]>=2)
			{
				if(ti[i]%3==1)
				{
					continue;
				}
				else if(ti[i]%3==0)
				{
					ch=(ti[i]/3)+1;
				}
				else
				{
					ch=(ti[i]/3)+2;
				}
				if(ch>=p)
				{
					che[i]=1;
					ans++;
					s--;
				}
			}
			if(s==0)
			{
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
