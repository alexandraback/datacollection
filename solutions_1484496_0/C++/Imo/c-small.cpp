#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long ll;

ll llpow(int a, int b) {
	ll r = 1;
	for (int i = 0; i < b; i++) r *= a;
}

void solve() {
	int N;
	scanf("%d", &N);
	int S[N];
	for (int i = 0; i < N; i++) scanf("%d", &S[i]);
	ll goal = llpow(3, N);
	for (int mask = 0; mask < goal; mask++) {
		ll mask_temp = mask;
		int a = 0, b = 0;
		for (int i = 0; i < N; i++) {
			int mode = mask_temp % 3;
			mask_temp /= 3;
			if (mode == 1) a += S[i];
			if (mode == 2) b += S[i];
		}
		if (a == b && a && b) {
			mask_temp = mask;
			vector<int> aa, bb;
			for (int i = 0; i < N; i++) {
				int mode = mask_temp % 3;
				mask_temp /= 3;
				if (mode == 1) aa.push_back(S[i]);
				if (mode == 2) bb.push_back(S[i]);
			}
			for (int i = 0; i < aa.size(); i++,
			    printf((i == aa.size()) ? "\n" : " ")) {
				printf("%d", aa[i]);
			}
			for (int i = 0; i < bb.size(); i++,
			    printf((i == bb.size()) ? "\n" : " ")) {
				printf("%d", bb[i]);
			}
			return;
		}
	}
	puts("Impossible");
}

int main() {
	int T;
	scanf("%d", &T);
	for (int case_x = 1; case_x <= T; case_x++) {
		printf("Case #%d:\n", case_x);
		solve();
	}
}