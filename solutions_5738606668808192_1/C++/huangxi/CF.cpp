//============================================================================
// Name        : CF.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#define  RD(x)      scanf("%d", &x)
#define  REP(i, n)  for (int i=0; i<int(n); ++i)
#define  FOR(i, n)  for (int i=1; i<=int(n); ++i)
#define  pii        pair<int, int>
#define  piL        pair<int, long long>
#define  mp         make_pair
#define  pb         push_back
#define  whatis(x)  cout << #x << ": " << x << endl;
//int dx[4] = {0, -1, 0, 1};
//int dy[4] = {1, 0, -1, 0};
using namespace std;
#define  N   123
#define  eps 1e-13
#define  pi  acos(-1.0)
#define  inf 0XFFFFFFFFFFFFFFFll
//#define  mod 1000000007ll
#define  LL  long long
#define  ULL unsigned long long

LL pmod(LL x, LL n, LL mod) {
	x %= mod;
	LL r = 1;
	while (n) {
		if (n & 1)
			r = r * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return r;
}

LL prim[N];
int num = 0;
void makePrim() {
	static bool flag[N];
	fill(flag, flag + N, false);
	for (int i = 2; i < N; i++) {
		if (flag[i] == false) {
			prim[num++] = i;
			for (int j = i * 2; j < N; j+=i)
				flag[j] = true;
		}
	}
}

LL factor(LL v, LL d) {
	REP(j, num) {
		LL ts = 0;
		for (LL i = 0, n = v; n != 0; i++, n /= 2) if (n & 1)
			ts = (ts + pmod(d, i, prim[j])) % prim[j];
		if (ts == 0)
			return prim[j];
	}
	return -1;
}

vector<int> ok(LL v) {
	vector<int> ret;
	for (int d = 2; d <= 10; d++) {
		LL x = factor(v, d);
		if (x == -1)
			return vector<int>(1, -1);
		ret.push_back(x);
	}
	return ret;
}

int Main() {

	ios_base::sync_with_stdio(0);
//	freopen("B-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	clock_t t1 = clock();

	makePrim();
//	cout << num << endl;

	cout << "Case #1:" << endl;
	int L = 32;

	int count = 0;

	for (LL s = 1; s < 1ll << (L - 1); s += 2) {
		LL v = s + (1ll << (L - 1));
		auto it = ok(v);
		if (it[0] == -1)
			continue;
		for (int i = L - 1; i >= 0; i--) {
			cout << ((v >> i) & 1);
		}
		for (int c : it)
			cout << " " << c;
		cout << endl;
		if (++count == 500)
			break;
	}


	return 0;

	int T; cin >> T;

	FOR(_T, T) {

		cout << "Case #" << _T << ": ";

	}

	return 0;
}


int main() {
	return Main();
}
