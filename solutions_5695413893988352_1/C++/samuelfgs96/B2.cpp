#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f

using namespace std;

const double PI = acos(-1.0);
typedef pair<int, int> pii;
typedef long long ll;
string c, j;
string RC, RJ;
int n; ll ans;

void solve (int i) {
//	cout << i << ": " << c << " " << j << endl;
	if (i == n) {
		ll C = 0, J = 0;
		for (int x = 0; x < n; x++) {
			C = (C * 10) + (c[x] - '0');
			J = (J * 10) + (j[x] - '0');
		}
		if (abs (C - J) < ans) {
			RC = c; RJ = j;
			ans = abs (C - J);
		}
		return ;
	}

	if (c[i] != '?' and j[i] != '?')  {
		solve (i + 1);
		return ;
	}

	int flag = 0;
	string C = c, J = j;
	for (int k = 0; k < i; k++) {
		if (c[k] > j[k]) {
			flag = 1;
		} else if (c[k] < j[k]) {
			flag = -1;
		}
		if (flag) break;
	}
	if (flag) {
		if (flag == 1) {
			if (c[i] == '?') c[i] = '0';
			if (j[i] == '?') j[i] = '9';
		} else {
			if (c[i] == '?') c[i] = '9';
			if (j[i] == '?') j[i] = '0';
		}
		solve (i + 1); 
		c = C; j = J;
		return ;
	}

	if (c[i] == '?' and j[i] != '?') {
		for (int k = 0; k < 10; k++) {
			c[i] = k + '0';
			solve (i + 1);
		}
		c[i] = '?';
		return ;
	} else if (c[i] != '?' and j[i] == '?') {
		for (int k = 0; k < 10; k++) {
			j[i] = k + '0';
			solve (i + 1);
		}
		j[i] = '?';
		return ;
	}

	c[i] = j[i] = '0';
	solve (i + 1);

	j[i] = '1';
	solve (i + 1);

	c[i] = '1'; j[i] = '0';
	solve (i + 1);

	c[i] = j[i] = '?';
	return ;
}
int main (void) {
	int t; scanf("%d\n", &t);
	for (int cases = 1; cases <= t; cases++) {
		ans = LLONG_MAX;
		cin >> c >> j;
		n = c.size();
		solve (0);
		if (RC[0] == '?' or RJ[0] == '?') {
			for (int i = 0; i < n; i++) RC[i] = RJ[i] = '0';
		} else if (RC[n-1] == RJ[n-1] and RC[n-1] == '?') RC[n-1] = RJ[n-1] = '0';
		cout << "Case #" << cases << ": " << RC << " " << RJ << endl;
	}
	return 0;
}
