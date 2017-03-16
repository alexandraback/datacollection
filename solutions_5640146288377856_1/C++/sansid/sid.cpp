#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	freopen("abc.txt","r",stdin);
	freopen("test.txt","w",stdout);
	
	long long int f,f1,n,m,k,ans;
	scanf("%lld",&f);
	for(f1=1;f1<=f;f1++)
	{
		scanf("%lld %lld %lld",&n,&m,&k);
		ans=m/k;
		n--;
		ans=ans*n;
		
		
		ans=ans+k;
		
		
		ans=ans+(m/k);
		if(m%k==0)
		ans--;
		
		printf("Case #%lld: %lld\n",f1,ans);
	}
	return 0;
}
