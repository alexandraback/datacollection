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

int T, A, B;

int main() {
	cin >> T;
	FOR(cs, 1, T+1) {
		cin >> A >> B;
		int p10 = 1;
		while (10 * p10 <= B) p10 *= 10;
		int res = 0;
		FOR(i, A, B) {
			int v = i;
			FOR(j, 0, 6) {
				int d = v%10;
				v /= 10;
				v += p10 * d;
				if (v == i) break;
				if (v > i && v <= B) res++;
			}
		}
		cout << "Case #" << cs << ": " << res << endl;
	}
	return 0;
}
