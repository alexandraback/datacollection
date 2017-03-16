
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

///////////////////////////////

string board, target;
int m, total, sum;

#define N 10
int table[N];

void kmp_precalc(string& s)
{
	table[0] = 0;
	int k = 0;
	for (int i = 1; i < SZ(s); i++) {
		while (k > 0 && s[k] != s[i])
			k = table[k - 1];
		if (s[k] == s[i])
			k++;
		table[i] = k;
	}
}

int kmp_search(string& p, string& t)
{
	int k = 0, matches = 0;
	REP (i, SZ(t)) {
		while (k > 0 && p[k] != t[i])
			k = table[k - 1];
		if (p[k] == t[i])
			k++;
		if (k == SZ(p)) {
			matches++;
			k = table[k - 1];
		}
	}
	return matches;
}

void bruteforce(int i, int s, string acc)
{
	if (i == s) {
		int res = kmp_search(target, acc);
		sum += res;
		m = max(m, res);
		total++;
		return;
	}
	REP (j, SZ(board)) {
		bruteforce(i + 1, s, acc + board[j]);
	}
}

void init()
{
	cout.precision(10);
}

void solve()
{	
	int k, l, s;
	cin >> k >> l >> s;
	cin >> board >> target;
	total = 0;
	m = 0;
	sum = 0;
	kmp_precalc(target);
	bruteforce(0, s, "");
	double ans = (double)m - (double)sum/total;
	cout << fixed << ans;
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
