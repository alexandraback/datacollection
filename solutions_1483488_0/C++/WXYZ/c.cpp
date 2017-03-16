#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int t,tt,a,b,i,j,s,x,z;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++)
	{
		scanf("%d %d",&a,&b);
		s=0;
		z=1;
		while (z*10<b)
			z*=10;
		for (i=a;i<=b;i++)
		{
			j=i;
			while (1)
			{
				x=j/z;
				j%=z;
				j=j*10+x;
				if (j<=b&&j>i)
					s++;
				else if (j==i)
					break;
			}
		}
		printf("Case #%d: %d\n",tt,s);
	}
	return 0;
}
