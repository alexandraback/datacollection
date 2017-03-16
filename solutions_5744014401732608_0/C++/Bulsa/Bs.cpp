#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <memory>
#include <bitset>

using namespace std;
using ll = long long;
#define FOR(i,a,b) for(ll i=(a); i<(b); ++i)
#define FORD(i,a,b) for(ll i=ll(b)-1; i>=(a); --i)

static ll B, M;
static bool edge[10][10];
static ll poss[10];

static bool rek(ll cur) {
	if(cur == B-1) {
		poss[B-1] = 1;
		FORD(i,0,B-1) {
			poss[i] = 0;
			FOR(j,i,B) {
				if(edge[i][j]) poss[i] += poss[j];
			}
		}
		return poss[0] == M;
	}
	FOR(mask, 0, 1<<(B-cur-1)) {
		FOR(i,0,B-cur-1) {
			ll to = i+cur+1;
			edge[cur][to] = mask & (1<<i);
		}
		if(rek(cur+1)) return true;
	}
	return false;
}

int main() {
	ll T; cin >> T;
	FOR(t,0,T) {
		FOR(i,0,10) FOR(j,0,10) edge[i][j] = false;
		cout << "Case #" << t+1 << ": ";
		cin >> B >> M;
		if(rek(0)) {
			cout << "POSSIBLE\n";
			FOR(i,0,B) {
				FOR(j,0,B) {
					cout << edge[i][j];
				}
				cout << endl;
			}
		} else {
			cout << "IMPOSSIBLE\n";
		}
	}
}
