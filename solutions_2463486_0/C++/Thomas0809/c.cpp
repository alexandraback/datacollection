#include<cstdio>
#include<iostream>
using namespace std;
long long a[11111],l,r;
int ans,num,T;

bool check(long long x)
{
	long long y=0,z=x;
	while (x)
	{
		y=y*10ll+(long long)(x%10);
		x/=10ll;
	}
	return y==z;
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	for (long long i=1; i<=1e7; i++)
		if (check(i) && check(i*i))
			a[++num]=i*i;
	scanf("%d",&T);
	for (int tt=1; tt<=T; tt++)
	{
		cin>>l>>r;
		ans=0;
		for (int i=1; i<=num; i++)
			if (a[i]>=l && a[i]<=r)
				ans++;
		cout<<"Case #"<<tt<<": "<<ans<<"\n";
	}
	return 0;
}