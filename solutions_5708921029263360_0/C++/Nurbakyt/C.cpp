#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size())
#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif
#define fname "."
#define pi pair < int, int >
#define pp pop_back

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int MAX_N = (int)2e5 + 123;
const double eps = 1e-6;
const int inf = (int)1e9 + 123;

using namespace std;

vector < pair < int, pi > > ans, st;
int a, b, c;
int K;
int cnt[12][12][12];
int counter;

void rec() {
	counter++;
	if (counter >= (int)2e6)
		return;
	if (sz(ans) < sz(st))
		ans = st;
	int mini = inf;
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			for (int k = 1; k <= c; k++) {
				if (!st.empty() && st.back() == mp(i, mp(j, k)))
					continue;
				mini = min(mini, max(cnt[i][j][0], max(cnt[i][0][k], cnt[0][j][k])));
			}
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			for (int k = 1; k <= c; k++) {
				if (!st.empty() && st.back() == mp(i, mp(j, k)))
					continue;
				if (cnt[i][j][0] < K && cnt[i][0][k] < K && cnt[0][j][k] < K && max(cnt[i][j][0], max(cnt[i][0][k], cnt[0][j][k])) <= mini + 2) {
					st.pb(mp(i, mp(j, k)));
					cnt[i][j][0]++, cnt[i][0][k]++, cnt[0][j][k]++;
					rec();
					st.pp();
					cnt[i][j][0]--, cnt[i][0][k]--, cnt[0][j][k]--;
				}
			}
}

void solve(int test) {
	cin >> a >> b >> c >> K;
	ans.clear();
	st.clear();
	memset(cnt, 0, sizeof cnt);
	counter = 0;
	rec();
	cout << "Case #" << test << ": " << sz(ans) << endl;
	for (auto i : ans)
		cout << i.f << ' ' << i.s.f << ' ' << i.s.s << endl;
}

int main() {
	#ifdef Nick
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
	#endif
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
		solve(i);		
	return 0;
}
