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

const int N = 100;

int z, n;
long long m;
int mat[N][N];

void solve(int tc) {
	cin >> n >> m;
	cout << "Case #" << tc << ": ";

	FORD(i, n-1, 1) REP(j, i+1, n) {
		mat[i][j] = 1;
	}
	REP(i, 0, n) mat[0][i] = 0;
	int j = n-2;
	if(n <= 63 && m > (1LL<<(n-2))) {
		
	}
	else {
		bool add = false;
		if(n <= 63 && m == (1LL<<(n-2))) {
			m--; add = true;
		}
		//long long k = 1;
		while(m && j) {
			if(m&1) mat[0][j] = 1;
			j--;
			m /= 2;
			//k *= 2;
		}
		if(add) {
			mat[0][n-1] = 1;
		}

	}
	if(m) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << "POSSIBLE" << endl;
		REP(i, 0, n) {
			REP(j, 0, n) {
				cout << mat[i][j];
			}
			cout << endl;
		}
	}
}

int main() {
  ios_base::sync_with_stdio(0);

  cin >> z;
  FOR(tc, 1, z) solve(tc);
}