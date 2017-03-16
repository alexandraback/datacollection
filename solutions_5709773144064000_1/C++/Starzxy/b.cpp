#include<cstdio>
#include<iostream>

using namespace std;

int t;
double c,f,x,now,ans;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		cin>>c>>f>>x;
		now=2.0;
		ans=0.0;
		
		for(;;)
			if(x/now<(c/now+x/(now+f)))
			{
				ans+=x/now;
				break;
			}
			else
			{
				ans+=c/now;
				now+=f;
			}
		
		printf("Case #%d: %.8lf\n",i,ans);
	}
	
	return 0;
}
