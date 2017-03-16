#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) do { if(0) fprintf(stderr, __VA_ARGS__); } while(0)
#define DBGDO(X) do { if(0) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; } while(0)

const ll MOD = 1e9 + 7;

ll fak(int n) {
	assert(n >= 0);
	if (n < 2) return 1;
	ll res = 1;
	FOR(i,2,n+1) {
		res = (res * i) % MOD;
	}
	return res;
}

int main() {
	FOR(i,0,5) DBGDO(fak(i));
	int TC;
	cin >> TC;
	FOR(tc,1,TC+1) {
		cout << "Case #" << tc << ": ";
		int N;
		cin >> N;

		vs car;
		ll possib = 1;

		vi first (26, -1);
		vi last (26, -1);
		vi inside (26, -1);
		vi full (26, 0);

		FOR(i,0,N) {
			string tmp;
			cin >> tmp;
			car.pb(tmp);

			char f = tmp.front(), l = tmp.back();
			if (tmp == string(sz(tmp), f)) {
				full[f-'a']++;
				continue;
			}

			if (f == l) possib = 0;

			if (first[f-'a'] == -1) first[f-'a'] = sz(car)-1;
			else                    possib = 0;

			if (last[l-'a'] == -1) last[l-'a'] = sz(car)-1;
			else                   possib = 0;

			int j = 1, k = sz(tmp)-1;
			while (j < k && tmp[j] == f) j++;
			while (j < k && tmp[k-1] == l) k--;
			FOR(i,j,k) {
				char c = tmp[i];
				if (c == f || c == l) possib = 0;

				if (c != tmp[i-1]) {
					if (inside[c-'a'] == -1)
						inside[c-'a'] = sz(car)-1;
					else
						possib = 0;
				}
			}
		}

		FOR(b,0,26) {
			if (inside[b] != -1) {
				if (full[b] > 0)     possib = 0;
				if (first[b] != -1)  possib = 0;
				if (last[b] != -1)   possib = 0;
			}
		}

		if (!possib) {
			cout << 0 << endl;
			continue;
		}

		vector<bool> done (26, false);
		int sections = 0;

		FOR(b,0,26) {
			if (done[b]) continue;
			if (first[b] == -1 && last[b] == -1 && full[b] == 0) continue;
			sections++;
			int f = b, l = b;
			while (true) {
				if (!done[f]) {
					done[f] = true;
					possib = (possib * fak(full[f])) % MOD;
				}

				int cf = last[f];
				if (cf == -1) break;

				int nf = -1;
				FOR(i,0,26) if (first[i] == cf) nf = i;
				if (nf == -1) break;
				f = nf;
				if (done[f]) { possib = 0; break; }
			}
			while (true) {
				if (!done[l]) {
					done[l] = true;
					possib = (possib * fak(full[l])) % MOD;
				}

				int cl = first[l];
				if (cl == -1) break;

				int nl = -1;
				FOR(i,0,26) if (last[i] == cl) nl = i;
				if (nl == -1) break;
				l = nl;
				if (done[l]) { possib = 0; break; }
			}
		}

		possib = (possib * fak(sections)) % MOD;

		cout << possib << endl;
	}
}
