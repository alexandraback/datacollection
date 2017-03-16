#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

const double kInf = 1e100;

int v[15];
int best[15];
double bp;
double dp[15];

map<long long, int> up;

double CalcP(int n) {
	up.clear();
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < (1 << (n + 1) / 2); ++i) {
		long long prod = 1;
		for (int j = n / 2; j < n; ++j) {
			if (i & (1 << (j - n / 2))) {
				prod *=  v[j];
			}
		}
		up[prod]++;
	}
	for (int i = 0; i < (1 << (n / 2)); ++i) {
		long long prod = 1;
		for (int j = 0; j < n / 2; ++j) {
			if (i & (1 << j)) {
				prod *=  v[j];
			}
		}
		for (auto p : up) {
			for (int j = 0; j < n; ++j) {
				if (v[j] == prod * p.first) {
					dp[j] += (double)p.second / (1 << n);
				}
			}
		}
	}
	double ret = 0;
	for (int j = 0; j < n; ++j) {
		if (dp[j] < 1e-26) {
			return -kInf;
		}
		ret += log(dp[j]);
	}
	return ret;
}

long long GetLCD(int k) {
	long long ret = 1;
	for (int i = 0; i < k; ++i) {
		int gcd = __gcd(ret, (long long)v[i]);
		ret /= gcd;
		ret *= v[i];
	}
	return ret;
}

void DFS(long long v, int pos, int n, int m) {
	if (pos == n) {
		if (v != 1) {
			return;
		}
		double p = CalcP(n);
		if (p > bp) {
			for (int i = 0; i < n; ++i) {
				best[i] = ::v[i];
			}
			bp = p;
		}
		return;
	} else if (pos == n - 1) {
		if (v == 1) {
			for (int i = 0; i < n - 1; ++i) {
				::v[n - 1] = ::v[i];
				double p = CalcP(n);
				if (p > bp) {
					for (int i = 0; i < n; ++i) {
						best[i] = ::v[i];
					}
					bp = p;
				}
			}
		}
	} else if (pos == n - 2) {
		if (v == 1) {
			for (int i = 0; i < n - 2; ++i) {
				for (int j = 0; j < n - 2; ++j) {
					::v[n - 1] = ::v[i];
					::v[n - 2] = ::v[j];
					double p = CalcP(n);
					if (p > bp) {
						for (int i = 0; i < n; ++i) {
							best[i] = ::v[i];
						}
						bp = p;
					}
				}
			}
		}
	}
	for (int i = m; i > 1; --i) {
		if (v % i == 0) {
			::v[pos] = i;
			DFS(v / i, pos + 1, n, i);
		}
	}
}

void solve(int n, int m, int k) {
	long long lcd = GetLCD(k);
	for (int i = 0; i < n; ++i) {
		best[i] = 2;
	}
	DFS(lcd, 0, n, m);
}


int main() {
	freopen("c_hard.in", "r", stdin);
	freopen("c_hard.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int I = 0; I < T; ++I) {
		printf("Case #%d:\n", I + 1);
		int n, m, r, k;
		scanf("%d%d%d%d", &r, &n, &m, &k);
		for (int j = 0; j < r; ++j) {
			cerr << j << endl;
			for (int i = 0; i < k; ++i) {
				scanf("%d", &v[i]);
			}
			bp = -kInf;
			solve(n, m, k);
			for (int i = 0; i < n; ++i) {
				printf("%d", best[i]);
			}
			puts("");
		}
	}
	return 0;
}