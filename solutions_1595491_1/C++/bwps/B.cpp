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

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int T, N, S, P, sc1[110], sc2[110], tab[110][110];

int rek(int p, int rem) {
	if (rem < 0) return -oo;
	if (p == N) return (rem == 0) ? 0 : -oo;
	int &res = tab[p][rem];
	if (res != -1) return res;
	res = -oo;
	if (sc1[p] != -1) {
		int v = rek(p+1, rem);
		if (v != -oo) res = max(res, sc1[p] + v);
	}
	if (sc2[p] != -1) {
		int v = rek(p+1, rem-1);
		if (v != -oo) res = max(res, sc2[p] + v);
	}
	return res;
}

int main() {
	cin >> T;
	FOR(cs, 1, T+1) {
		cin >> N >> S >> P;
		FOR(i, 0, N) {
			int sum;
			cin >> sum;
			sc1[i] = sc2[i] = -1;
			FOR(a, 0, 11) FOR(b, a, 11) FOR(c, b, 11) {
				if (c-a > 2 || a+b+c != sum) continue;
				if (c-a == 2) {
					if (c >= P) {
						sc2[i] = max(sc2[i], 1);
					} else {
						sc2[i] = max(sc2[i], 0);
					}
				} else {
					if (c >= P) {
						sc1[i] = max(sc1[i], 1);
					} else {
						sc1[i] = max(sc1[i], 0);
					}
				}
			}
		}
		memset(tab, -1, sizeof(tab));
		cout << "Case #" << cs << ": " << rek(0, S) << endl;
	}
	return 0;
}
