#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a,b,c,d,i,j,l,sum,result,n,m,k,s,t,r;
    scanf("%lld",&t);
    b=0;
    while(t--)
    {
    	scanf("%lld%lld%lld",&r,&c,&k);
    a=c/k;
    a*=r;
    if(c%k==0)
    printf("Case #%lld: %lld\n",++b,a+k-1);
    else
    printf("Case #%lld: %lld\n",++b,a+k);
	
    }
		return 0;
}




