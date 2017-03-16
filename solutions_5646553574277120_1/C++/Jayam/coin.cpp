#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long int a[1000001];
long long int small(long long int arr[], long long int n,long long int c)
{
   long long int res = 1;
   for (long long int i = 0; i < n && arr[i] <= res; i++)
       res = res + (arr[i]*c);
 
   return res;
}
int main()
{
	long long int t,T,c,d,v,i,j,ans,tp;	
	scanf("%lld",&T);
	for(t=1;t<=T;t++)
	{
		ans=0;
		scanf("%lld %lld %lld",&c,&d,&v);
		for(i=0;i<d;i++)
			scanf("%lld",&a[i]);
		
		tp=small(a,d,c);
		while(tp<=v)
		{
			a[d++]=tp;
			sort(a,a+d);
			ans++;
			tp=small(a,d,c);
		}
		printf("Case #%lld: %lld\n",t,ans);
	}
	return 0;
}
