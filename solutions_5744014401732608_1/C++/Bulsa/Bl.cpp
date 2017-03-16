#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <memory>
#include <bitset>
#include <cassert>

using namespace std;
using ll = long long;
#define FOR(i,a,b) for(ll i=(a); i<(b); ++i)
#define FORD(i,a,b) for(ll i=ll(b)-1; i>=(a); --i)

static ll B, M;
static bool edge[100][100];
static ll poss[100];

static bool rek(ll cur) {
	if(cur == B-1) {
		poss[B-1] = 1;
		FORD(i,0,B-1) {
			poss[i] = 0;
			FOR(j,i,B) {
				if(edge[i][j]) poss[i] += poss[j];
			}
		}
		cerr << "got " << poss[0] << endl;
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
		cout << "Case #" << t+1 << ": ";
		cin >> B >> M;
		if(M <= 1LL<<(B-2)) {
			cout << "POSSIBLE\n";
			FOR(i,0,B) {
				FOR(j,0,B) {
					if(j <= i) {
						cout << (edge[i][j] = 0);
					} else if(i == 0) {
						if(M == 1LL<<(B-2))
							cout << (edge[i][j] = 1);
						else if(j != B-1)
							cout << (edge[i][j] = bool(M&(1LL<<(B-j-2))));
						else
							cout << (edge[i][j] = 0);
					} else if(j == 0) {
						cout << (edge[i][j] = 0);
					} else {
						cout << (edge[i][j] = 1);
					}
				}
				cout << endl;
			}
			assert(rek(B-1));
		} else {
			cout << "IMPOSSIBLE\n";
		}
	}
}
