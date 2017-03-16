// lamphanviet@gmail.com
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define EPS 1e-7
#define MAX 100111
#define MOD 1000000007

const string w[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
const char sc[] = { 'Z', 'X', 'G', 'W', 'H', 'R', 'S', 'F', 'I', 'O' };
const int num[] = { 0, 6, 8, 2, 3, 4, 7, 5, 9, 1 };
string s;
int cnt[300];

void del(int d) {
	rep(i, w[d].length()) cnt[w[d][i]]--;
}

void solve() {
	vi res;

	fill(cnt, 0);
	rep(i, s.length()) cnt[s[i]]++;

	rep(i, 10) {
		while (cnt[sc[i]] > 0) {
			res.pb(num[i]);
			del(num[i]);
		}
	}

	rep(i, 300) if (cnt[i]) {
		puts(">>>>>>>>>>failed>>>>>>>>>>>");
	}

	sort(all(res));
	rep(i, res.size()) printf("%d", res[i]);
}

int main() {
	//ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		cin >> s;
		printf("Case #%d: ", ++caseNo);
		solve();
		puts("");
	}
	return 0;
}

