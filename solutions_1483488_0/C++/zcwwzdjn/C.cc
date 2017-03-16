#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

namespace {
	int t, a, b, pow10[7], lis[7], lis_idx;
	char buf[8];

	int Calc(int l, int r) {
		int res = 0;
		for (int x = l, y; x <= r; ++ x) {
			sprintf(buf, "%d", x);
			int sz = strlen(buf);
			y = x;
			lis_idx = 0;
			for (int j = 0; j < sz - 1; ++ j) {
				y = y % pow10[sz - 1] * 10 + buf[j] - '0';
				if (y >= l && y <= r && y > x) lis[lis_idx ++] = y;
			}
			sort(lis, lis + lis_idx);
			res += unique(lis, lis + lis_idx) - lis;
		}
		return res;
	}

	void Solve(FILE *fin, FILE *fout) {
		pow10[0] = 1;
		for (int i = 1; i < 7; ++ i) pow10[i] = pow10[i - 1] * 10;
		fscanf(fin, "%d", &t);
		for (int cas = 0; cas ++ < t; ) {
			fscanf(fin, "%d%d", &a, &b);
			fprintf(fout, "Case #%d: %d\n", cas, Calc(a, b));
		}
	}
}

int main() {
	::Solve(stdin, stdout);
	return 0;
}
