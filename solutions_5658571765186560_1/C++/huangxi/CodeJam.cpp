//============================================================================
// Name        : CodeJam.cpp
// Author      : ccdd4211
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
#define  whatis(x)  cout << #x << ": " << x << endl
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

using namespace std;
#define  N   1234678
#define  eps 1e-8
#define  pi  acos(-1.0)
#define  inf 0XFFFFFFFFFFFFFFll
#define  mod 1000000007ll
#define  LL  long long
#define  ULL unsigned long long

string work(int x, int r, int c) {
	if (r > c)
		swap(r, c);

	if (r * c % x != 0)
		return "RICHARD";

	for (int i = 1; i <= x + 1 - i; i++) {
		int j = x + 1 - i;
		if (r < i || c < j)
			return "RICHARD";
	}

	if (x >= 7)
		return "RICHARD";

	if (x > r) {
		int sum = x - r;
		for (int p = 1; p <= sum; p++) {
			for (int q = 1; q <= sum; q++) {
				if (p + q + 1 >= r) {
					for (int ls = p; ls <= p * r; ls++) {
						int rs = sum - ls;
						if (rs >= q && rs <= q * r) {
							bool ok = false;
							for (int z = p + 1; z + q <= c; z++) {
								int cao = (z - 1) * r - ls;
								int fuck = (c - z) * r - rs;
								if (cao % x == 0 && fuck % x == 0) {
									ok = true;
									break;
								}
							}
							if (!ok)
								return "RICHARD";
						}
					}
				}
			}
		}
	}


	return "GABRIEL";
}
int Main() {
	freopen("D-large.in", "r", stdin);
	freopen("codejam.out", "w", stdout);


	int T;
	cin >> T;

	FOR(_T, T) {
		int x, r, c;
		cin >> x >> r >> c;
		cout << "Case #" << _T << ": " << work(x, r, c) << endl;
	}

	return 0;
}


int main() {
	return Main();
}
