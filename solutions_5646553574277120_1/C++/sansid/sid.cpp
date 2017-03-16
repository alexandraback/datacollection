#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

long long int dp[10006],dv[10006],a[10006];
int main()
{
	freopen("abc.txt","r",stdin);
	freopen("test.txt","w",stdout);
	
	long long int f,f1,c,d,v,i,j,k,ans,x;
	scanf("%lld",&f);
	for(f1=1;f1<=f;f1++)
	{
		scanf("%lld %lld %lld",&c,&d,&v);
		for(i=0;i<d;i++)
		scanf("%lld",&a[i]);
		
		sort(a,a+d);
		a[d]=v+1;
		
		x=1;
		ans=0;
		i=0;
		while(1)
		{
			if(x>v)
			break;
			//printf("%lld %lld\n",x,a[i]);
			if(a[i]<=x)
			{
				x=x-1+a[i]*c;
				i++;
				x++;
			}
			else
			{
				ans++;
				x=x-1+x*c;
				x++;
			}
			//printf("%lld %lld\n",x,ans);
		}
		printf("Case #%lld: %lld\n",f1,ans);
	}
	return 0;
}
