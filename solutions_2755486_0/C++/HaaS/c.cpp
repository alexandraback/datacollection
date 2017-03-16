#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define int long long
#define double long double

#define ff first
#define ss second
#define mp make_pair
#define sqr(x) ((x)*(x))

typedef long long ll;
typedef pair <int, int> pie;

const int maxN = 1000 + 10;
const int maxA = 2000 * 1000 + 100;

int Alls[maxA];

int N, d[maxN], n[maxN], w[maxN], e[maxN], s[maxN], dd[maxN], dp[maxN], ds[maxN];

struct attack {
	int s, l, r, d;
	attack(){}
	attack(int S, int L, int R, int D) { s = S, l = L, r = R, d = D; }
};

bool operator < (attack a, attack b) {
	if (a.d != b.d) return a.d < b.d;
	if (a.s != b.s) return a.s < b.s;
	if (a.l != b.l) return a.l < b.l;
	return a.r < b.r;
}


int solve() {
	memset (Alls, 0, sizeof Alls);
	int *All = &Alls[maxA/2];
	cin >> N;
	vector <attack> a;
	for (int i = 0; i < N; i++) {
		cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
		for (int j = 0, S = s[i], l = w[i], r = e[i], day = d[i]; j < n[i]; j++) {
			a.push_back (attack (S, l, r, day));
			S += ds[i], l += dp[i], r += dp[i], day += dd[i];
		}
	}
	int res = 0;
	sort (a.begin(), a.end());
	//for (int i = 0; i < a.size(); i++) {
	//	cerr << a[i].d << ": " << a[i].l << ' ' << a[i].r << ' ' << a[i].s << endl;
	//}
	for (int i = 0; i < a.size(); ) {
		int k = i; while (k < a.size() && a[k].d == a[i].d) k++;
		for (int l = i; l < k; l++) {
			bool valid = 0;
			for (int j = a[l].l; j < a[l].r; j++)
				if (All[j] < a[l].s) valid = 1;
			res += valid;
		}
		for (int l = i; l < k; l++)
			for (int j = a[l].l; j < a[l].r; j++)
				if (All[j] < a[l].s) All[j] = a[l].s;
		i = k;
	}
	return res;
}

main() {
	ios::sync_with_stdio (false);
	
	int tests; cin >> tests;
	for (int o = 1; o <= tests; o++) {
		int ans = solve();
		cout << "Case #" << o << ": " << ans << endl;
	}

	return 0;
}
