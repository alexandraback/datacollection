#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;

#define debug(x) cout << #x << "=" << x << endl
#define sqr(x) ((x)*(x))

typedef long long ll;

int tests,n;
ll r,t;

int ok(ll x)
{
	if ((2.0*r+2*x-1)*x >t*2 || (2*r+2*x-1)*x > t)
		return 0;
	return 1;
}

int main()
{
	freopen("a1.in","r",stdin);
	freopen("a1.out","w",stdout);
	
	scanf("%d",&tests);
	for (int test=1;test<=tests;test++)
	{
		cin >> r >> t;
		ll lef = 0, rig = (ll)sqrt(t), mid;
		while (lef < rig)
		{
			mid = (lef + rig) / 2;
			if (ok(mid))
				lef = mid+1;
			else rig = mid;
		}
		//debug(lef); debug(rig);
		printf("Case #%d: ",test);
		cout << lef-1 << endl;
	}
	
	return 0;
}
