#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
using namespace std;
int main()
{
	int testcases,test,r,t,area,k,count;
	scanf("%d",&testcases);
	for(test=1;test<=testcases;test++)
	{
		scanf("%d%d",&r,&t);
		area=0;
		k=0;
		count=0;
		while(true)
		{
			if((area+((r+k+1)*(r+k+1))-((r+k)*(r+k)))<=t)
			{
				area+=(((r+k+1)*(r+k+1))-((r+k)*(r+k)));
				k+=2;
				count++;
			}
			else
				break;
		}
		printf("Case #%d: %d\n",test,count);
	}
	return 0;
}