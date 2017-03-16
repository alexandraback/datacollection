#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <climits>
#include <stack>
#define FOR(i,p,k) for(int i = (p);i<(k);i++)
typedef long long int LL;
using namespace std;

int t;

void dane()
{
	cin>>t;
	FOR(przy,0,t)
	{
		int a,b,k;
		cin>>a>>b>>k;
		if(a>b)
		{
			int c = b;
			b=a;
			a=c;		
		}
		//A jest wieksze
		LL all = min(a,k)*b;
		
		if(k<a)
		{
			FOR(i,k,a)
			{
				FOR(j,0,b)
				{
				
					if((i&j)<k)
						all++;
				}				
			}
		}
		printf("Case #%d: %lld\n",przy+1,all);
	}
}

int main()
{
	dane();
	return 0;
}
