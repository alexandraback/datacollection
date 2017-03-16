#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
	freopen("B-large.in","r",stdin);freopen("out.txt","w",stdout);
	int T,cas=0;
	int N,S,p;
	int sco[200];
	int a[200],b[200],c[200];
	cin>>T;
	while(T--)
	{
		cas++;
		scanf("%d %d %d",&N,&S,&p);
		printf("Case #%d: ",cas);
		int ans=0,i;
		for(i=1;i<=N;i++) scanf("%d",&sco[i]);
		for(i=1;i<=N;i++)
		{
			if(sco[i]%3==0) a[i]=b[i]=c[i]=sco[i]/3;
			if(sco[i]%3==1)
			{
				a[i]=b[i]=sco[i]/3;
				c[i]=b[i]+1;
			}
			if(sco[i]%3==2)
			{
				a[i]=sco[i]/3;
				b[i]=c[i]=a[i]+1;
			}
		}
		for(i=1;i<=N;i++)
		{
			if(c[i]>=p) ans++;
			else
			{
				if(sco[i]%3==0 && c[i]+1==p && a[i]>=1 && S>0)
				{
					ans++;
					S--;
				}
				if(sco[i]%3==2 && a[i]+2==p && S>0)
				{
					ans++;
					S--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
