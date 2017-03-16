#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
void E(){}template<class A,class...B>void E(A _,B...$){cerr<<' '<<_;E($...);}
#define E($...) E(#$,'=',$,'\n')

const int L = 32;
int64_t dyn[L][2][2][2];

int64_t cnt(bool unb, int v, int l) {
	if (unb) return 1 << l;
	for (; l < L-1; ++l) v &= ~(1<<l);
	return v;
}
int64_t cntk(bool unb, int v, int l) {
	if (unb) return 1;
	for (; l < L-1; ++l) v &= ~(1<<l);
	return v != 0;
}

void process() {
	int a, b, k;
	cin >> a >> b >> k;
	memset(dyn, 0, sizeof(dyn));
	dyn[L-1][1][1][1] = 1;
	int64_t ans = 0;
	for (int l = L-2; l >= 0; --l) {
		int al = (a&(1<<l))?1:0, bl = (b&(1<<l))?1:0, kl = (k&(1<<l))?1:0;

		for (int ay = 0; ay <= 1; ++ay) for (int by = 0; by <= 1; ++by) for (int ky = 0; ky <= 1; ++ky) {
			int at = ay ? al : 1; int bt = by ? bl : 1; int kt = ky ? kl : 1;
			for (int ax = 0; ax <= at; ++ax) for (int bx = 0; bx <= bt; ++bx) for (int kx = 0; kx <= kt; ++kx) {
				bool au = ay ? ax < at : 1;  bool bu = by ? bx < bt : 1; bool ku = ky ? kx < kt : 1;
				if ((ax&bx) > kx) continue;
				else if ((ax&bx) < kx) {
					int64_t dans = dyn[l+1][ay][by][ky] * cnt(au, a, l) * cnt(bu, b, l) * cnt(ku, k, l);
					if (0&&dans) {
						E(dans, dyn[l+1][ay][by][ky]);
						E(ay, by, ky);
						E(ax, bx, kx);
						E(cnt(au, a, l), cnt(bu, b, l));
					}
					//ans += dans;
				}
				else {
					dyn[l][!au][!bu][!ku] += dyn[l+1][ay][by][ky];
				}
			}
		}
	}
	ans += dyn[0][0][0][0];
	printf("%ld\n", ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	int tcases;
	cin >> tcases;
	for (int tcase = 1; tcase <= tcases; ++tcase) {
		printf("Case #%d: ", tcase);
		process();
	}
	return 0;
}
