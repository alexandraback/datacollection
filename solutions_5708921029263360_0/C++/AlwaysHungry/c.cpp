#include <bits/stdc++.h>

#define ALL(v) v.begin(), v.end()
#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define REPD(i, a, b) for (int i = a; i > b; i--)
#define REPLL(i, a, b) for (ll i = a; i < b; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define FORLL(i, a, b) for (ll i = a; i <= b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef pair<ld, ld> pld;

#define remax(a, b) a = max(a, b)
#define remin(a, b) a = min(a, b)

#define popcount __builtin_popcount
#define pb push_back
#define mp make_pair
#define st first
#define y first
#define nd second
#define x second

#define eps 1e-9
#define pi acos(-1.0)

//const int inf = 1e9 + 1;

const int N = 14;

int z, n, j, p, s, k;
long long m;
int mat[N][N];

struct ans {
	int a, b, c;
};

vector<ans> res;

int dp[3][N][N]; // OXX, XOX, XXO

void solve(int tc) {
	cin >> j >> p >> s >> k;
	cout << "Case #" << tc << ": ";

	res.clear();
	REP(_, 0, 3) FOR(a, 1, 10) FOR(b, 1, 10) dp[_][a][b] = 0;

	int cur = 1;
	FOR(a, 1, j)
	FOR(b, 1, p) {
		FOR(c, 1, s) {
			//int c = cur;
			if(dp[0][b][c] < k && dp[1][a][c] < k && dp[2][a][b] < k) {
				dp[0][b][c]++;
				dp[1][a][c]++;
				dp[2][a][b]++;
				cur++;
				res.pb({a, b, c});
			}
			if(cur > s) cur = 1;
		}
	}
	
	cout << res.size() << endl;
	for(ans o : res) {
		cout << o.a << " " << o.b << " " << o.c << endl;
	}
}

int main() {
  ios_base::sync_with_stdio(0);

  cin >> z;
  FOR(tc, 1, z) solve(tc);
}