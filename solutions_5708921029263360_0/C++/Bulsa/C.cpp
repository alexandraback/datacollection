#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <memory>
#include <bitset>
#include <random>
#include <sstream>

using namespace std;
using ll = long long;
#define FOR(i,a,b) for(ll i=(a); i<(b); ++i)

using comb = array<int,3>;
static int J, P, S, K;

int main() {
	ll T; cin >> T;
	FOR(t,0,T) {
		cout << "Case #" << t+1 << ": ";
		cin >> J >> P >> S >> K;
		//cout << "paramters " << J << " " << P << " " << S << " " << K << endl;
		if(J == 1 && P == 1) {
			int res = min(K,S);
			cout << res << endl;
			FOR(i,0,res) {
				cout << "1 1 " << i+1 << endl;
			}
		} else if(J == 1) {
			int res = min(K,S)*P;
			cout << res << endl;
			FOR(shift,0,min(K,S)) {
				FOR(i,0,P) {
					cout << "1 " << i+1 << " " << (i+shift)%S+1 << endl;
				}
			}
		} else {
			int res = 0;
			int shift = 0;
			int k = 0;
			stringstream r;
			FOR(j,0,J) {
				FOR(p, 0, P) {
					if(shift == S) continue;
					r << j+1 << " " << p+1 << " " << (p+shift)%S+1 << endl;
					++res;
				}
				++k;
				if(k == K) {
					++shift;
					k = 0;
				}
			}
			cout << res << endl;
			cout << r.str();
		}
	}
}
