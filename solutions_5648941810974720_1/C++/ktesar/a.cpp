#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>
#include <iostream>
#include <sstream>
#include <cctype>

#define PI 3.14159265358979
#define EPS 1e-9

using namespace std;

#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, m, n) for (int i=m; i<=n; i++)
#define ABS(a) (((a)>0)?(a):(-(a)))
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;

char r[10] = {'Z', 'O', 'W', 'H', 'R', 'F', 'X', 'S', 'G', 'I'};
char word[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[26];
int order[10] = {0, 2, 6, 8, 3, 4, 5, 7, 1, 9};

int f(char c) {
	return c-'A';
}

void solve() {
	REP(i, 26) cnt[i] = 0;
	string s; cin >> s;
	REP(i, s.size()) {
		cnt[f(s[i])]++;
	}
	vector<int> res;
	REP(k, 10) {
		int x = order[k];
		int c = f(r[x]);
		int amount = cnt[c];
		REP(i, amount) res.push_back(x);
		REP(i, strlen(word[x])) {
			cnt[f(word[x][i])] -= amount;
		}
	}
	sort(res.begin(), res.end());
	REP(i, res.size()) cout << res[i];
	cout << endl;
}

int main() {
	int t; scanf("%d", &t);
	REP(i, t) {
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}
