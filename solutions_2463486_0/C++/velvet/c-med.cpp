#include<cstdio>
#include<iostream>
#include<string>
#include<set>
#include<cmath>
#define maxn 10000009
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
//int f[maxn];
set<ii> Q;
bool mirror(ll a)
{
	string s;
	for (;a;a/=10) s.push_back(a%10+'0');
	int n=s.size();
	for (int i=0;i<n;i++)
		if (s[i]!=s[n-i-1]) return 0;
	return 1;
}
ll find(ll a)
{
	ll f=0;
	set<ii>::iterator it;
	it=Q.upper_bound(ii(a,0x7fffffff));
//	cout<<it->first<<endl;
	if (it--==Q.begin()) return 0;
	return it->second;
}

int main()
{
	int T,a,b;
	int cnt=0;
	cin>>T;
	for (int i=1;i<=10000000;i++)
		if (mirror(i) && mirror(1ll*i*i))
			Q.insert(ii(1ll*i*i,++cnt));
	for (int run=1;run<=T;run++)
	{
		printf("Case #%d: ",run);
		cin>>a>>b;
		ll f=find(b);
		f-=find(a-1);
		cout<<f<<endl;
		// check answer
		/*
		ll check=0;
		for (int i=sqrt(a)-1;i<=sqrt(b)+2;i++)
			if (i*i>=a && i*i<=b && mirror(i) && mirror(i*i))
			{
				check++;
				cout<<i<<' '<<i*i<<endl;
			}
		cout<<check<<endl;
		*/
	}
	return 0;
}
