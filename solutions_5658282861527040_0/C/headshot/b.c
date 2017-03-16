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
	int t,t1,n,i,j,m,k;
	cin>>t;
	t1=t;
	while(t--)
	{
		scanf("%d%d%d",&m,&n,&k);
		int ct=0;
		printf("Case #%d: ",t1-t);
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				int y=i&j;
				//printf("Y is: %d\n",y);
				if(y<k)
				{
				//	printf(" its < %d\n",k);
					ct++;
				}
			}
		}
		printf("%d\n",ct);
	}
	return 0;
}
