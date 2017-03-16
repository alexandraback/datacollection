#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++) 
#define FORR(i,b) FOR(i,0,b)
#define FORE(i, a, b) for(int i = a; i >= b; --i)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back
#define CLR(x,e) memset(x, e, sizeof x)

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll gcd (ll a, ll b) { return (b ? gcd (b, a%b) : a); }
ll mmc (ll a, ll b) { return a / gcd (a, b) * b; }

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	
	int T;
	cin>>T;
	FORR (caso, T) {
		cout << "Case #" << caso+1 << ": ";
		int K, C, S; 
		cin>>K>>C>>S;
		if (S*C<K) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			vector<int> vec(200, 0);
			FORR (i, K) vec[i] = i;
			int pos = 0;
			vector<ll> res;
			FORR (i, S) {
				ll X = 1;
				ll ans = 1;
				FORR (j, C) {
					ans += vec[pos++] * X;
					X *= K;		
				}
				res.pb (ans);
				if (pos>K) break;
			}
			FORR (i, sz(res)) cout << res [i] << " "; cout << endl;
		}
	}
}	
