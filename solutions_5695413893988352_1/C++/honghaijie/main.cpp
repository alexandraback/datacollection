#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <limits>
#include <algorithm>
#include <ctime>
#include <cstring>
#include <climits>

using namespace std;

typedef long long LL;

int cs = 0;
string a, b;
int n;
LL dis, ra, rb;

string to_string(LL x) {
    char s[100];
    sprintf(s, "%lld", x);
    string res(s);
    return string(n - res.length(), '0') + res;
}

void dfs(int step, LL x, LL y) {
	if (step == n) {
		if (dis > abs(x - y)) {
			dis = abs(x - y);
			ra = x; rb = y;
		}
		else if (dis == abs(x - y)) {
			if (x < ra || (x == ra && y < rb)) {
				dis = abs(x - y);
				ra = x; rb = y;
			}
		}
		return;
	}
	int da, db;
	if (x > y) {
		if (a[step] == '?' && b[step] == '?') {
			dfs(step + 1, x * 10 + 0, y * 10 + 9);
		}
		else if (a[step] == '?') {
			da = db = b[step] - '0';
			da = 0;
			dfs(step + 1, x * 10 + da, y * 10 + db);
		}
		else if (b[step] == '?') {
			da = db = a[step] - '0';
			db = 9;
			dfs(step + 1, x * 10 + da, y * 10 + db);
		}
		else {
			dfs(step + 1, x * 10 + a[step] - '0', y * 10 + b[step] - '0');
		}
	}
	else if (x < y) {
		if (a[step] == '?' && b[step] == '?') {
			dfs(step + 1, x * 10 + 9, y * 10 + 0);
		}
		else if (a[step] == '?') {
			db = b[step] - '0';
			da = 9;
			dfs(step + 1, x * 10 + da, y * 10 + db);
		}
		else if (b[step] == '?') {
			da = a[step] - '0';
			db = 0;
			dfs(step + 1, x * 10 + da, y * 10 + db);
		}
		else {
			dfs(step + 1, x * 10 + a[step] - '0', y * 10 + b[step] - '0');
		}
	}
	else {
		if (a[step] == '?' && b[step] == '?') {
			dfs(step + 1, x * 10 + 0, y * 10 + 0);
			dfs(step + 1, x * 10 + 0, y * 10 + 1);
			dfs(step + 1, x * 10 + 1, y * 10 + 0);
		}
		else if (a[step] == '?') {
			db = b[step] - '0';
			dfs(step + 1, x * 10 + db, y * 10 + db);
			if (db != 9)
				dfs(step + 1, x * 10 + db + 1, y * 10 + db);
			if (db != 0)
				dfs(step + 1, x * 10 + db - 1, y * 10 + db);
		}
		else if (b[step] == '?') {
			da = a[step] - '0';
			dfs(step + 1, x * 10 + da, y * 10 + da);
			if (da != 9)
				dfs(step + 1, x * 10 + da, y * 10 + da + 1);
			if (da != 0)
				dfs(step + 1, x * 10 + da, y * 10 + da - 1);
		}
		else {
			dfs(step + 1, x * 10 + a[step] - '0', y * 10 + b[step] - '0');
		}
	}
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		dis = LLONG_MAX;
		n = a.length();

		dfs(0, 0, 0);
		printf("Case #%d: ", ++cs);
		cout << to_string(ra) << " " << to_string(rb) << endl;
	}
	return 0;
}
