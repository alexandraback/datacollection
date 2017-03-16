
// Author: Tiago Togores

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(), (a).end()
#define CLR(a, x) memset(a, x, sizeof a)
#define REP(i, n) for (auto i = 0; i < (n); i++)
#define FORT(it, l) for (auto it = (l).begin(); it != (l).end(); it++)
#define READLINE(line) cin.getline((line), sizeof (line))
#define VALID(i, j, n, m) (0 <= (i) && (i) < (n) && 0 <= (j) && (j) < (m))
#define PI M_PI
#define EPSILON 1e-6
#define INF 1000000000
#define MOD 1000000007
#define endl '\n'
//NOTE: append ll to name if using long long
#define BITCOUNT __builtin_popcount
#define BITLEAD0 __builtin_clz
#define BITTRAIL0 __builtin_ctz
#define BITPARITY __builtin_parity

typedef unsigned int uint;
typedef long long int int64;
typedef pair<int64,int> ii;

///////////////////////////////

#define N 1000010
bitset<N> visited;

void init()
{
	
}

int64 reverse(int64 n)
{
	string s = to_string(n);
	reverse(ALL(s));
	return stoll(s);
}

void solve()
{
	int64 n, m;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return;	
	}
	queue<ii> q;
	q.push(ii(1, 1));
	visited.reset();
	visited[1] = 1;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		// cout << x.ST << " " << x.ND << endl;
		m = x.ST + 1;
		REP (i, 2) {
			if (!visited[m] && m <= n) {
				if (m == n) {
					// cout << (x.ND + 1) << " " << SZ(visited) << " " << n;
					cout << (x.ND + 1);
					return;
				}
				q.push(ii(m, x.ND + 1));
				visited[m] = 1;
			}
			m = reverse(x.ST);
		}
	}
}

int main()
{ _
	init();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
		cout << endl;
	}
	return 0;
}
