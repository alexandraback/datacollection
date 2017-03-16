#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <utility>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cctype>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

#define rep(i,n) for(int i=0; i<n; i++) 
#define repa(i,s,e) for(int i=s; i<=e; i++)
#define repd(i,s,e) for(int i=s; i>=e; i--)

int T;
ll E, R, N;
ll v[10000001];

ll solve() {
	ll g= 0;
	ll e = E;
	for(ll i=0; i<N-1; i++) {
		ll f = 0;
		bool isLarge = false;
		for(ll j=i+1; j<N; j++) {
			if(v[i] < v[j]) {
				isLarge = true;
				f = j - i;
				break;
			}
		}

		if(!isLarge) {
			g += e * v[i];
			e = R;
		} else {
			ll r = min(max(0LL, R * f + e - E), E);
			g += r * v[i];
			e = e - r + R;
		}
	}
	g += e * v[N-1];
	return g;
}

int main() {
	cin>>T;
	rep(t,T) {
		cin>>E>>R>>N;
		rep(i,N) cin>>v[i];
		printf("Case #%d: %lld\n", t+1, solve());
	}
}
