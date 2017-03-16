#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <assert.h>
#include <functional>
#define SUBMIT 1
using namespace std;
typedef long long int lld;
void f() {
	freopen("c:\\icpc\\input.txt", "r", stdin);
	freopen("c:\\icpc\\output.txt", "w", stdout);
}
lld lld_pow(lld a, lld b) {
	lld res = 1;
	while (b--) res *= a;
	return res;
}
vector<int> dec_to_bin(lld N, const lld digits) {
	vector<int> res(digits, 0);

	for (int i = digits - 1; i >= 0; i--) {
		lld w = lld_pow(2, i);
		if (N >= w) {
			res[i] = 1;
			N -= w;
		}
	}
	reverse(res.begin(), res.end());

	return res;
}
int m[51][51];
lld B, M;
void print_map() {
	for (int i = 1; i <= B; i++) {
		for (int j = 1; j <= B; j++) {
			printf("%d", m[i][j]);
		}
		printf("\n");
	}
}
int main(void) {
	if (SUBMIT) f();
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		printf("Case #%d: ", tc);

		
		scanf("%lld %lld", &B, &M);
		
		for (lld i = 1; i <= B; i++) {
			for (lld j = 1; j <= B; j++) {
				if (i < j) m[i][j] = 1;
				else m[i][j] = 0;
			}
		}

		lld max_possibles = lld_pow(2, B-2);
		bool possible = (M <= max_possibles);

		if (possible) {
			printf("POSSIBLE\n");

			if (M == max_possibles) {
				print_map();
			}
			else {
				vector<int> bin = dec_to_bin(max_possibles- M, B - 2);
				for (int i = 0; i < bin.size(); i++) {
					if (bin[i]) m[1][i + 2] = 0;
				}
				print_map();
			}

		}
		else {
			printf("IMPOSSIBLE\n");
		}
		
	}
}