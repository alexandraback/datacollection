#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cassert>

using namespace std;
using ll = long long;
#define FOR(i,a,b) for(ll i=(a); i<(b); ++i)

int main() {
    ll T; cin >> T;
    FOR(t,0,T) {
        cout << "Case #" << t+1 << ": ";

		ll N; cin >> N;
		vector<ll> adj(N);
		for(ll& x : adj) {
			cin >> x;
			--x;
		}

		map<ll,ll> seen; //id->pos
		set<ll> left;
		FOR(i,0,N) left.insert(i);

		ll res = 0;
		ll i = 0;

		while(left.size()) {
			ll start = i;
			ll cur = *begin(left);
			left.erase(begin(left));
			while(!seen.count(cur)) {
				seen[cur] = i;
				cur = adj[cur];
				++i;
			}
			if(seen[cur] >= start) {
				res = max(res,i-seen[cur]);
			}
		}
		vector<bool> loop(N);
		vector<ll> lens(N);
		FOR(i,0,N) {
			if(adj[adj[i]] == i)
				loop[i] = true;
		}
		FOR(i,0,N) {
			seen.clear();
			ll cur = i;
			ll len = 0;
			while(!seen.count(cur)) {
				seen[cur] = i;
				cur = adj[cur];
				++len;
			}
			if(loop[cur]) {
				lens[cur] = max(lens[cur], len-2);
			}
		}
		ll sum = 0;
		FOR(i,0,N) {
			sum += lens[i];
			if(loop[i]) ++sum;
		}

		cout << max(res,sum);

		cout << endl;
    }
}
