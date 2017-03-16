#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define PRIMES 1000

using namespace std;

typedef long long LL;

vector<int> P;
vector<pair<int, vector<int>>> J;
bool isp[PRIMES];

bool is_jc(int n, vector<int>& F) {
	for (int b = 2; b <= 10; b++) {
		LL v = 0;
		int t = n;
		for (LL p = 1; t; p *= b, t >>= 1)
			v += (t % 2) * p;
		bool d = false;
		for (int pi  : P) {
			if (v % LL(pi) == 0) {
				d = true;
				F.push_back(pi);
				break;
			}
		}
		if (! d)
			return false;
	}
	return true;
}

int main() {
	int t, h, i, j, n, m;
	for (i = 0; i < PRIMES; i++)
		isp[i] = true;
	for (i = 2; i < PRIMES; i++) {
		if (isp[i]) {
			P.push_back(i);
			for (j = 2 * i; j < PRIMES; j += i)
				isp[i] = false;
		}
	}
	scanf("%d %d %d", &t, &n, &m);
	int f = 0;
	for (int c = 0; f < m; c++) {
		h = (c << 1) | 1 | (1 << (n - 1));
		vector<int> F;
		if (is_jc(h, F)) {
			J.push_back(make_pair(h, F));
			f++;
		}
	}
	printf("Case #1:\n");
	for (i = 0; i < (int)J.size(); i++) {
		vector<int> C;
		for (h = J[i].first; h; h >>= 1)
			C.push_back(h % 2);
		reverse(C.begin(), C.end());
		for (int j1 : C)
			printf("%d", j1);
		for (int j2 : J[i].second)
			printf(" %d", j2);
		printf("\n");
	}
}
