#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <iostream>

using namespace std;

typedef long long ll;

// 1, 2, 3, 4 represents 1, i, j, k, respectively
int quaqua(int q1, int q2) {
	if (q1 < 0) return -quaqua(-q1, q2);
	if (q2 < 0) return -quaqua(q1, -q2);
	if (q1 == 1) return q2;
	if (q2 == 1) return q1;
	if (q1 == q2) return -1;
	if (q1 == 2) return q2 == 3 ? 4 : -3;
	if (q1 == 3) return q2 == 2 ? -4 : 2;
	if (q1 == 4) return q2 == 2 ? 3 : -2;
	assert(0);
}

int c2q(char c) {
	if (c == '1') return 1;
	else return c - 'g';
}

void output(int t, bool success) {
	printf("Case #%d: %s\n", t+1, success ? "YES" : "NO");
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		ll L, X;
		scanf("%lld%lld", &L, &X);
		string str;
		cin >> str;
		
		bool success = false;
		int rep;
		bool gen_i;
		
		int prod = 1;
		for (int i = 0; i < L; i++) {
			prod = quaqua(prod, c2q(str[i]));
		}
		int prodall = 1;
		for (int i = 0; i < X % 4; i++) prodall = quaqua(prodall, prod);
		if (prodall != -1) {
			//cout <<"prodall == " << prod << endl;
			goto END;
		}
		
		rep = X % 4 + 24;
		if (rep > X) rep = X;
		
		prod = 1;
		gen_i = false;
		for (int r = 0; r < rep; r++) {
			for (int i = 0; i < L; i++) {
				prod = quaqua(prod, c2q(str[i]));
				if (gen_i && prod == 3) {
					success = true;
					goto END;
				}
				else if (!gen_i && prod == 2) {
					gen_i = true;
					prod = 1;
				}
			}
		}
		
		END:;
		output(t, success);
	}
	return 0;
}
