#include<iostream>
using namespace std;
long long a,b;
long long gcd()
{
	long long temp,ta=a,tb=b;
	while (tb!=0)
	{
		temp=ta;
		ta=tb;
		tb=temp%tb;
	}
	return ta;
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	long long ans,c,T;
	cin>>T;
	for (int k=0;k<T;k++)
	{
		scanf("%lld/%lld",&a,&b);
		c=gcd();
		a=a/c;
		b=b/c;
		cout<<"Case #"<<k+1<<": ";
		long long temp=b;
		while (temp!=1&&temp%2==0) temp=temp/2;
		if (temp==1)
		{
			ans=1;
			while ((a*2<b)&&(b%2==0))
			{
				b=b/2;
				ans++;
			}
			if (b%2==0) cout<<ans<<endl;
			else cout<<"impossible"<<endl;
		}
		else cout<<"impossible"<<endl;
	}
	return 0;
}