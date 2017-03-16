#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define inf 1000000000
#define maxn 1000000

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define sin scanint
#define bitcount(x) __builtin_popcount(x)
#define fill(s, p) memset(s, p, sizeof(s));
#define gc getchar

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

ll modpow(ll a, ll b)
{
	ll x=1ll, y=a;
	while(b){
		if(b%2)
			x=(x*y)%MOD;
		y=(y*y)%MOD;
		b/=2;
	}
	return x;
}

ll gcd(ll a, ll b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b, a%b);
}

int main()
{
	#ifndef ONLINE_JUDJE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t, n, r, w, c, ans, ca=1;
	sin(t);
	while(t--){
		sin(r);
		sin(c);
		sin(w);
		n = (r*c);
		ans = ceil((float)n/w)+(w-1);
		printf("Case #%d: %d\n", ca++, ans);
	}
	return 0;
}