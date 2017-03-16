#include <string>
#include <set>
#include <ctime>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define INF 1000000000

const int MOD = 1000000007;
bool used1[55], used[55];
int n, ans = 0;
int a[55][105];
int p[55];
int len[55];

bool check() {
	int last = -1;
	for (int i = 0; i < 26; ++i) used[i] = false;
	for (int i = 0; i < n; ++i) {
		int u = p[i];
		for (int j = 0; j < len[u]; ++j)
			if (last != a[u][j]) {
				if (last == -1) last = a[u][j];
				else {
					used[last] = true;
					if (used[a[u][j]]) return false;
					last = a[u][j];
				}
			}
	}
	return true;
}


void rec(int x) {
	if (x == n) {
		if (check()) ans++;
		return ;
	}

	for (int i = 0; i < n; ++i) {
		if (!used1[i]) {
			used1[i] = true;
			p[x] = i;
			rec(x+1);
			used1[i] = false;
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		len[i] = s.size();
		for (int j = 0; j < (int)s.size(); ++j)
			a[i][j] = s[j] - 'a';
	}
	ans = 0;
	rec(0);
	cout << ans << endl;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	for (int tests = 1; tests <= t; ++tests) {
		cout << "Case #" << tests << ": ";
		solve();
	}
	return 0;
}