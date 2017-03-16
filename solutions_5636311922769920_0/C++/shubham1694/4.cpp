#include <bits/stdc++.h>

using namespace std;

#define sd(x) scanf("%d", &x)
#define boost ios_base::sync_with_stdio(false);
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define f first
#define s second

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 1000000007;
const int inf = 50000000;
const int maxn = 100010;

ll modpow(ll a, ll b)
{
	ll x=1, y=a;
	while(b){
		if(b&1)
			x = (x*y);
		y = (y*y);
		b/=2;
	}
	return x;
}

vector<ll> pts;

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	int t, cn=1;
	ll k, c, s, i, x, y, j, len, st, en, req;
	scanf("%d", &t);
	while(t--){
		pts.clear();
		scanf("%lld%lld%lld", &k, &c, &s);
		req = (k+c-1)/c;
		if(req>s){
			printf("Case #%d: IMPOSSIBLE\n", cn++);
			continue;
		}
		for(i=1; i<=k; i+=c){
			x = i;
			y = min(i+c-1, k);
			len = modpow(k, c-1);
			st = len*(i-1) + 1ll;
			en = st + len -1ll;
			for(j=x+1; j<=y; j++){
				len/=k;
				st = st + len*1ll*(j-1);
				en = st + len - 1ll;
			}
			pts.pb(st);
		}
		printf("Case #%d:", cn++);
		for(auto it:pts)
			printf(" %lld", it);
		printf("\n");
	}
	return 0;
}
