#include<map>
#include<set>
#include<iostream>
#include<string.h>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<memory.h>
#include <iomanip>
using namespace std;

#define mp make_pair
#define X first
#define Y second

double const eps = 1e-10;
int const INF = 100000;
int const MOD = 1;
int const MAX = 5*100*1000 + 5;

long long gcd(long long a, long long b)
{
	if(a == 0)
		return b;
	return gcd(b%a, a);
}

int main()
{
#ifdef _DEBUG
    freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif
	int t, tt;
	cin >> t;
	for(tt = 0; tt < t; ++tt)
	{
		cout << "Case #" << tt + 1 <<": ";
		long long p, q;
		char c;
		cin >> p >> c >> q;
		long long g = gcd(p, q);
		p /= g;
		q /= g;
		long long r = q;
		while(r % 2 == 0)
			r/= 2;
		if(r > 1)
		{
			cout << "impossible" << endl;
			continue;
		}
		long long s = (q + p - 1)/p;
		int ans;
		for(ans = 0; ((long long)1 << ans) < s; ++ans);
		cout << ans << endl;
	}
	return 0;
}