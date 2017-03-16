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
	
	int obj = (1<<10)-1;
	int L; cin>>L;
	FORR (caso, L) {
		int N; cin>>N;
		cout << "Case #" << caso+1 << ": ";
		if (N==0) {
			cout << "INSOMNIA" << endl;
		} else {
			int mask = 0;
			ll X = N;
			while (obj!=mask) {
				ll cp = X;
				while (cp) {
					ll tmp = cp%10;
					mask |= (1<<tmp);
					cp /= 10;
				}
				X += N;
			}
			cout << X-N << endl;	
		}
	}
}	
