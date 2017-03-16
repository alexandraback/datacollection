#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define pb push_back
#define mp make_pair
#define ST begin()
#define ED end()
#define XX first
#define YY second
#define elif else if 
#define foreach(i,x) for (__typeof((x).ST) i=(x).ST;i!=(x).ED;++i) 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vci;
typedef vector<string> vcs;
typedef pair<int,int> PII;

ll n, m;

ll calc(ll n, ll x)
{
//	double z=1.*x*n*n+1.*2*n*((x-1)*2)*x/2+1.*x*(x-1)*(2*x-1)*2/3;
	ll p=n*2+1, q=p+(x-1)*4;
	double z=1.*(p+q)*x/2;
	if (z>5e18) return m+1;
//	ll zz=x*n*n+n*2*((x-1)*2)*x/2+x*(x-1)*(2*x-1)*2/3;
	ll zz=(p+q)*x/2;
	return zz;
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);

	int task;
	scanf("%d", &task);
	for (int _i=1;_i<=task;++_i)
	{
		cin>>n>>m;
		ll l=1,r=m;
		while (l<r)
		{
			ll x=(l+r+1)>>1;
			if (calc(n,x)<=m)
				l=x;
			else
				r=x-1;
		}
		cout<<"Case #"<<_i<<": "<<l<<endl;
	}

	return 0;
}
