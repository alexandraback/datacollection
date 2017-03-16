#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)

typedef pair<int, int> pii;
typedef long long ll;

vector<int> best;
vector<int> cur;
int pairs[3][10][10];
int j, p, s, k;

void rec(int a, int b, int c) {
	// cout << a << ' ' << b << ' ' << c << endl;
	if (c > s) { rec(a, b+1, 1); return; }
	if (b > p) { rec(a+1, 1, 1); return; }
	if (a > j) {
		if (cur.size() > best.size()) best = cur;
		return;
	}
	int c1 = ++pairs[0][a][b];
	int c2 = ++pairs[1][b][c];
	int c3 = ++pairs[2][a][c];
	if (c1 <= k && c2 <= k && c3 <= k) {
		cur.push_back(a + b * 16 + c * 16 * 16);
		rec(a,b,c+1);
		cur.pop_back();
	}
	pairs[0][a][b]--;
	pairs[1][b][c]--;
	pairs[2][a][c]--;
	rec(a,b,c+1);
}

void solve() {
	cin >> j >> p >> s >> k;
	best.clear();
	rec(1,1,1);
	cout << best.size() << endl;
	for (int i : best) {
		REP (j, 3) {
			cout << i % 16 << ' ';
			i /= 16;
		}
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;
	REP(i, t) {
		cout << "Case #" << (i+1) << ": ";
		solve();
	}
}