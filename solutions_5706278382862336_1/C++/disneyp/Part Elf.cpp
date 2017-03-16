#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
long long gcd(long long x,long long y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
void solve(int tt)
{
	long long p,q,r,pp,qq,ans=0,cnt=0;
	scanf("%lld/%lld",&p,&q);
	if(p>q) 
	{
		printf("Case #%d: impossible\n",tt+1);
		return;
	}
	r=gcd(p,q);
	p=p/r;
	q=q/r;
	pp=p;qq=q;
	//cout << endl << p << " " << q << endl;
	while(q!=1)
	{
		if(q==0||q%2==1)
		{
			ans=0;
			break;
		}
		q=q/2;
		cnt++;
		ans=1;
	}
	if(ans==0)
	{
		printf("Case #%d: impossible\n",tt+1);
		return;
	}
	cnt=0;
	while(pp<qq)
	{
		qq=qq/2;
		cnt++;
	}
	
	
	printf("Case #%d: %lld\n",tt+1,cnt);
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t;
	cin >> t;
	for(int i=0;i<t;i++) solve(i);
}