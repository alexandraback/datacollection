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
    		scanf("%lld",&m);
    		arr[m]=1;
    	}
    	sum=0;count=0;
    	for(i=1;i<=b;i++)
    	{
    		if(arr[i]==1)
    		sum+=i;
    		else
    		{
    			if(sum<i)
    			{
    				count++;
    				sum+=i;
//    				printf("%lld ",i);
    			}
    			
    			
    		}
    	}
    	printf("Case #%lld: %lld\n",++a,count);
    }
	return 0;
}




