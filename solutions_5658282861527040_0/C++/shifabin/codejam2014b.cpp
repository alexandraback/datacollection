#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int ii,i,j,tot,a,b,k,tt,p;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d",&tt);
	for(ii=1;ii<=tt;ii++)
	{
		scanf("%d%d%d",&a,&b,&k);
		tot=0;
		for(i=0;i<a;i++)
			for(j=0;j<b;j++)
			{
				if (((i&j))<k) tot++;
			}
		printf("Case #%d: %d\n",ii,tot);
	}
	return 0;
}