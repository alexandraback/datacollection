#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;
int main()
{

freopen("aj.in", "r", stdin);
  freopen("aj.out", "w", stdout);
	long long int t,p=0;
	scanf("%lld",&t);
	while(t--)
	{

	long long int a,b,k,i,j,c=0,x,y=1;
	scanf("%lld %lld %lld",&a,&b,&k);

	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			x=i&j;
			if(x<k)
			{

		//	printf("%d %d\n",i,j);
			c++;
		    }
		}
	}
	printf("Case #%lld: %lld\n",++p,c);

}
return 0;
}
