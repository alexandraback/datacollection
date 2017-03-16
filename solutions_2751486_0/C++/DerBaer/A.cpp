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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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
#define mp make_pair
#define pb push_back

int main() {
	int tc;
	cin >> tc;
	FOR(t, 1, tc+1) {
		string s;
		int n;
		cin >> s >> n;
		
		set<pii> se;
		int nc = 0;
		FOR(po, 0, n) {
			if (s[po] != 'a' && s[po] != 'e' && s[po] != 'i' && s[po] != 'o' && s[po] != 'u') {
				nc++;
			}
		}			
		int po = 0;
		if (nc >= n) {
			FOR(i, 0, po+1) FOR(j, po+n-1, s.size()) se.insert(mp(i, j));
		}
		while(po + n < s.size()) {
			if (s[po] != 'a' && s[po] != 'e' && s[po] != 'i' && s[po] != 'o' && s[po] != 'u') {
				nc--;
			}
			if (s[po+n] != 'a' && s[po+n] != 'e' && s[po+n] != 'i' && s[po+n] != 'o' && s[po+n] != 'u') {
				nc++;
			}
			po++;
			if (nc >= n) {
				FOR(i, 0, po+1) FOR(j, po+n-1, s.size()) se.insert(mp(i, j));
			}
		}
		
		
		cout << "Case #" << t << ": " << se.size() << endl;
	}
	return 0;
}
