#include <iostream>
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
int a,b ;
int sum[1001] ;
bool check1(int x)
{
	vector<int> ret ;
	ret.clear() ;
	int xx = x ;
	while (xx>0)
	{
		int r = xx%10 ;
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
bool check(int x)
{
	if (!check1(x)) return false ;
	for (int i=1;i<=400;i++)
	{
		if (i*i>1000) break ;
		if (i*i==x)
		{
			if (check1(i)) return true ;
			return false ;
		}
	}
	return false ;
}
int main()
{
	memset(sum,0,sizeof(sum)) ;
	for (int i=1;i<=1000;i++)
	{
		sum[i] = sum[i-1] ;
		if (check(i))
		{
			sum[i]++ ;
		//	cout<<i<<endl ;
		}
	//	cout<<i<<" "<<sum[i]<<endl ;
	}
	int cs ;
	cin>>cs ;
	for (int t=1;t<=cs;t++)
	{
		cin>>a>>b ;
		if (a>b) swap(a,b) ;
		printf("Case #%d: %d\n",t,sum[b]-sum[a-1]) ;
	}
}