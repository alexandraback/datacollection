#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <sstream>
using namespace std ;
long long a,b ;
long long p[1000000] ;
bool check(long long x)
{
	vector<long long> ret ;
	ret.clear() ;
	long long xx = x ;
	while (xx>0)
	{
		long long r = xx%10 ;
		ret.push_back(r) ;
		xx /= 10 ;
	}
	int n = ret.size() ;
	for (int i=0;i<n/2;i++)
	{
		if (ret[i]!=ret[n-1-i])
		{
			return false ;
		}
	}
	return true ;
}
int main()
{
	memset(p,0,sizeof(p)) ;
	int cnt = 0 ;
	for (long long i=1;i<=10000000;i++)
	{
		if (check(i)&&check(i*i))
		{
			p[++cnt] = i*i ;
		}
	}
	sort(p+1,p+cnt+1) ;
	cnt = unique(p+1,p+cnt+1) - (p+1) ;
	int cs ;
	cin>>cs ;
	for (int i=1;i<=cs;i++)
	{
		cin>>a>>b ;
		int s=0,t=0 ;
		for (int j=cnt;j>=0;j--)
		{
			if (p[j]<a)
			{
				s = j ;
				break ;
			}
		}
		for (int j=cnt;j>=0;j--)
		{
			if (p[j]<=b)
			{
				t = j ;
				break ;
			}
		}
		printf("Case #%d: %d\n",i,t-s) ;

	}
}