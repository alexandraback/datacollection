#include <bits/stdc++.h>
using namespace std;
#define N 101
int f[N][2];

int solve(string s) {
	memset(f, -1, sizeof(f));
	f[0][0] = s[0] == '+'?1: 0;
	f[0][1] = s[0] == '-'?1: 0;
	int n = (int)s.size();
	for (int i=1; i<n; i++) {
		if (s[i] == '+') {
			f[i][0] = min(f[i-1][0] + 2, f[i-1][1] + 1);
			f[i][1] = min(f[i-1][0] + 1, f[i-1][1]);
		} else if (s[i] == '-') {
			f[i][0] = min(f[i-1][0], f[i-1][1] + 1);
			f[i][1] = min(f[i-1][0] + 1, f[i-1][1] + 2);
		}
	}
	return f[n-1][1];
}


int main () {
	int cas;
	string s;
	cin >> cas;
	for (int i=1; i<=cas; i++) {
		cin >> s;
		printf("Case #%d: %d\n", i, solve(s));
	}
	return 0;
}
