#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	ll temp;
	while(a!=0)
	{
		temp=b%a;
		b=a;
		a=temp;
	}
	return b;
}
int main()  
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T;
	ll p,q,cnt,g;
	scanf("%d",&T);
	for(int rr=1;rr<=T;rr++)
	{
		cnt=0;
		scanf("%lld/%lld",&p,&q);
		g=gcd(p,q);
		p/=g;
		q/=g;
		while(p<q)
		{
			if(q%2==0)
			{
				cnt++;
				q>>=1;
			}
			else
			{
				printf("Case #%d: impossible\n",rr);
				break;
			}
		}
		if(p>=q)
		{
			while(q!=1)
				if(q%2==0)
					q>>=1;
				else
				{
					printf("Case #%d: impossible\n",rr);
					break;
				}
			if(q==1)
				printf("Case #%d: %lld\n",rr,cnt);
		}
	}
	return 0;
}