#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          pii;
typedef vector<pii>             vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;

#define VAR(a,b)        __typeof(b) a=(b)
#define REP(i,n)        for(int i=0;i<(n);++i)     // 0 to n
#define FOR(i,a,b)      for(VAR(i,a);i<=(b);++i)  // a to b, a < b
#define FORD(i,a,b)     for(VAR(i,a);i>=(b);--i)  // a to b, a > b
#define FORE(a,b)       for(VAR(a,(b).begin());a!=(b).end();++a) // for each, e.g. FORE(iter, vect) cout << *iter << endl;
#define SIZE(a)         ((int)((a).size())) // e.g. for (int i = 0; i < SIZE(vect); ++i)
#define ALL(x)          (x).begin(),(x).end() // e.g. sort(ALL(vect))
#define FILL(x,a)       memset(x,a,sizeof(x))
#define CLR(x)          memset(x,0,sizeof(x))
#define VE              vector<int>
#define SZ              size()
#define PB              push_back
#define MP              make_pair
#define FI              first
#define SE              second

// Numeric functions
bool isPowOf2(int i){return (i & i-1) == 0;} //NOTES: isPowOf2

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		int n;
		double val;
		vector<double> naomi;
		vector<double> ken;

		cin >> n;

		for (int i = 0; i < n; i++) {
			scanf("%lf", &val);
			naomi.PB(val);
		}

		for (int i = 0; i < n; i++) {
			scanf("%lf", &val);
			ken.PB(val);
		}

		sort(naomi.begin(), naomi.end(), greater<double>());
		sort(ken.begin(), ken.end(), greater<double>());

		int pn = 0;
		int pk = 0;

		int k1 = 0, n1 = 0, k2 = 0, n2 = 0;

		while (k1 < n && k2 < n && n1 < n && n2 < n) {
			if (naomi[n1] > ken[k1]) {
				pn++;
				n1++;
				k1++;
			} else {
				k1++;
			}

			if (ken[k2] > naomi[n2]) {
				pk++;
				n2++;
				k2++;
			} else {
				n2++;
			}
		}





		printf("Case #%d: %d %d\n", i, pn, n - pk);

	}

   	return 0;
}
