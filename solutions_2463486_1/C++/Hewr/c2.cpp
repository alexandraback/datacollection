// c cheat big1 Hewr
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define SIZE(x) ((int) (x).size())

typedef long long LL;

vector<LL> Q;

bool chk(LL x) {
	string s = "";
	while (x) {
		s += (char)(x % 10 + '0');
		x /= 10;
	}
	for (int i = 0; i < SIZE(s); ++i) {
		int j = SIZE(s) - 1 - i;
		if (j <= i) break;
		if (s[i] != s[j]) return false;
	}
	return true;
}

int qry(LL x) {
	for (int i = 0; i < SIZE(Q); ++i) if (Q[i] > x) return i;
	return SIZE(Q);
}

int main() {
	for (int i = 1; i <= (int) 1e7; ++i) if (chk(i)) {
		LL x = (LL) i * i;
		if (chk(x)) 
			Q.push_back(x);
	}

	int CA;
	cin >> CA;
	for (int Ca = 1; Ca <= CA; ++Ca) {
		LL l, r;
		cin >> l >> r;
		printf("Case #%d: %d\n", Ca, qry(r) - qry(l - 1));
	}
}
