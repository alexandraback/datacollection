#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;
int main()
{

freopen("indian.in", "r", stdin);
  freopen("indian.out", "w", stdout);
	long long int test,p=0;
	scanf("%lld",&test);
	while(test--)
	{

	long long int a,b,k,i,j,c=0,x,mult,y=1;
	scanf("%lld %lld %lld",&a,&b,&k);
     mult=a*b;
	for(i=k;i<a;i++)
	{
		for(j=k;j<b;j++)
		{
			x=i&j;
			if(x>=k)
			{
			c++;
		    }
		}
	}
	printf("Case #%lld: %lld\n",++p,mult-c);

}
return 0;
}
