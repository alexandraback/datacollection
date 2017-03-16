#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		long long int p,q;
		scanf("%lld/%lld",&p,&q);
		//printf("%lld/%lld\n",p,q );
		int count=0, limit=0, flag=1;
		while(limit<=45)
		{
			if(flag)count++;
			limit++;
			if(2*p<q)
			{
				p*=2;
			}
			else if(2*p>q)
			{
				flag=0;
				p=2*p-q;
			}
			else
			{
				break;
			}
		}
		if(limit<=40) printf("%d\n",count );
		else printf("impossible\n");
	}

}