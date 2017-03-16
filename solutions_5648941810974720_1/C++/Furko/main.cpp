#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define mp make_pair
#define x first
#define y0 smthngy0
#define y1 smthngy1
#define y second
#define sz(A) (int)A.size()
#define RFOR(i,a,b) for (int (i) = (a); (i) >= (b); --(i))
#define ll long long
#define str fuck2
#define ld long double
#define sz(A) (int)A.size()

#define FREIN(FILE) freopen(FILE,"rt",stdin)
#define FREOUT(FILE) freopen(FILE,"wt",stdout)

typedef vector < int > vi;
typedef pair <int, int> pii;
const int MOD = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1000000000; //1e9
const int inf = 1e9+1;
const double eps = 1e-9;
char str[N];
string numbers[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string s;
vector < pair < char, int > > ch;
void ADD(pair < char, int > c) {
	ch.pb(c);
}
int cnt[1005];
void solve() {
	scanf("%s", str);
	
	s = str;
	int n = sz(s);
	memset(cnt, 0, sizeof(cnt));
	
	REP(i, n) {
		cnt[s[i]]++;
	}
	ch.clear();
	vi ans;
	ADD(mp('Z', 0));ADD(mp('W', 2));ADD(mp('U', 4));ADD(mp('X', 6));ADD(mp('G', 8));
	ADD(mp('F', 5));ADD(mp('T', 3));ADD(mp('S', 7));ADD(mp('I', 9));ADD(mp('N', 1));
	for (auto e : ch) {
		int tmp = cnt[e.x];
		REP(it, tmp) {
			REP(i, sz(numbers[e.y])) {
				cnt[numbers[e.y][i]]--;
			}
			ans.pb(e.y);
		}
	}
	sort(ans.begin(),ans.end());
	for (auto e : ans) {
		cout << e;
	}
	cout << endl;
}
int main(){
  FREIN("input.txt");
	FREOUT("output.txt");
	int tests;
	scanf("%d", &tests);
	REP(it, tests) {
		printf("Case #%d: ", it + 1);
		solve();
	}
	return 0;
}
