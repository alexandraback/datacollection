#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
	int t,u;
	cin>>t;
	u=t;
	while(t--)
	{
		ll p,q,g,i=0,cnt=0,flag=0;
		scanf("%lld/%lld",&p,&q);
		ll a[40]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608LL,16777216LL,33554432LL,67108864LL,134217728LL,268435456LL,536870912LL,1073741824LL,2147483648LL,4294967296LL,8589934592LL,17179869184LL,34359738368LL,68719476736LL,137438953472LL,274877906944LL,549755813888LL};
		cout<<"Case #"<<u-t<<": ";
		g=gcd(p,q);
		p=p/g;
		q=q/g;
		for(i=0;i<40;i++)
		{
			if(q==a[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"impossible"<<endl;
		}
		else if(flag==1)
		{
			for(i=0;i<=40;i++)
			{
				if(p/q>=1)
				{
					break;
				}
				else 
				{
					p=2*p;
					g=gcd(p,q);
					p=p/g;
					q=q/g;
					cnt=cnt+1;
				}

			}
			if(cnt<=40)
			{
				cout<<cnt<<endl;
			}
			else
			{
				cout<<"impossible"<<endl;
			}
		}
	}
	return 0;

}