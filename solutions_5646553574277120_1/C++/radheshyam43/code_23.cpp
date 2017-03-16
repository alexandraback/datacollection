#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a,b,c,d,i,j,l,sum,count,v,n,m,k,s,t;
    scanf("%lld",&t);a=0;
    while(t--)
    {
    	long long arr[105]={0};
    	scanf("%lld%lld%lld",&c,&d,&b);
    	for(i=0;i<d;i++)
    	{
    		scanf("%lld",&arr[i]);
    	}
    	sort(arr,arr+d);
    	arr[d]=b+1;
    	sum=0;count=0;
    	for(i=0;i<=d&&sum<b;i++)
    	{
    		if(sum<arr[i]-1)
    		{
   				count++;
   				l=sum+1;
   				sum+=(l*c);
//    			printf("%lld ",l);
    			i--;
    			continue;
   			}
   			sum+=(arr[i]*c);
    	}
    	printf("Case #%lld: %lld\n",++a,count);
    }
	return 0;
}




