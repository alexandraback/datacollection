/*	Problem A	*/
/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}
bool pow2(long long int n)
{
	long long int q=2;
	while(q<n)
	{
		q*=2;
	}
	if(n%q==0)
		return true;
	else
		return false;
}
int main()
{
	int t;
	cin>>t;
	for(int tcase=1;tcase<=t;++tcase)
	{
		long long int p,q;
		scanf("%lld/%lld",&p,&q);
		long long int fac=gcd(p,q);
		p/=fac;
		q/=fac;
		cout<<"Case #"<<tcase<<": ";
		if(!pow2(q))
		{
			cout<<"impossible\n";
		}
		else
		{
			long long int ans=0;
			while(p/q<1)
			{
				p*=2;
				ans++;
			}
			cout<<ans<<endl;	
		}
	}
	return 0;
}
