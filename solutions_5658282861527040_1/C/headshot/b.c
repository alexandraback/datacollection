#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <cstdio>
#include <list>
#include <iterator>

using namespace std;
//char a[105][200];
int main() 
{
	// your code goes here
	long long int t,t1,n,i,j,m,k;
	cin>>t;
	t1=t;
	while(t--)
	{
		scanf("%lld%lld%lld",&m,&n,&k);
	long long	int ct=0;
		if(m<k)
			ct=m*n;
		else
	{
		ct=k*n;
	//printf("ct was %d\n",ct);
		}
		printf("Case #%lld: ",t1-t);
		
		for(i=k;i<m;i++)
		{
			ct+= min(k,n);
			for(j=k;j<n;j++)
			{
				long long int y=i&j;
				//printf("Y is: %d\n",y);
				if(y<k)
				{
				//	printf(" its < %d\n",k);
					ct++;
				}
			}
		}
		printf("%lld\n",ct);
	}
	return 0;
}
