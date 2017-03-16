#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std ;
int main()
{
	freopen("D:\B-small-attempt0 (1).in","r",stdin) ;
	freopen("D:\B-small-attempt0 (1).out","w",stdout) ;
	int t ;
	scanf("%d",&t) ;
	for(int cas=1 ;cas<=t ;cas++)
	{
		int a,b,k ;
		scanf("%d%d%d",&a,&b,&k) ;
		int ans=0 ;
		for(int i=0 ;i<=a-1 ;i++)	
		{
			for(int j=0 ;j<=b-1 ;j++) 
				if((i&j)<k)ans++ ;
		} 
		printf("Case #%d: %d\n",cas,ans) ; 
	}
	return 0 ;
}