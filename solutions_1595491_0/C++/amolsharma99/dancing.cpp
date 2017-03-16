#include<iostream>	
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cassert>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UINT;
int gcd( int a, int b ) {  if( !b ) return a;  return gcd( b, a % b ); }

int main()
{
	int tc,n,s,p,t;
	int i,j,k,count=0;
	scanf("%d",&tc);
	for(i=0;i<tc;i++)
	{
		count=0;
		scanf("%d%d%d",&n,&s,&p);
		for(j=0;j<n;j++)
		{	
			scanf("%d",&t);
			if(t/3>=p)
				count++;
			else
			{
				k=t-p;
				if( k>=(2*p-2) && k>=0 && p>0)
					count++;
				else if(k>=(2*p-4) && s>0 && k>=0 && p>0)
				{
					count++;
					s--;
				}
			}
		}
		printf("Case #%d: %d\n",i+1,count);
	}
	return 0;
}

