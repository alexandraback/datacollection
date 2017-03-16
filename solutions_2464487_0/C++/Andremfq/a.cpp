#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int t;
long long int r,ta;
int main()
{
	scanf("%d",&t);
	for(int w=1;w<=t;w++)
	{
		scanf("%lld %lld",&r,&ta);
		long long int ini=1;
		long long int fim=sqrt(ta/2)+1;
		//printf("fim=%lld \n",fim);
		long long int ra=2*r-1;
		while(ini<fim)
		{
			//printf("%lld %lld\n",ini,fim);
			long long int m=(ini+fim)/2;
			if(ini==fim-1) m=fim;
			if(ra <= (ta-(2*m*m))/m)
			{
				ini=m;
			}
			else
			{
				fim=m-1;
			}
		}
		printf("Case #%d: %lld\n",w,ini);
	}
	return 0;
}
