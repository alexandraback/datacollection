#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int T, N, S, p, angka;

int main () {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d", &N);
		scanf("%d", &S);
		scanf("%d", &p);
		int ans = 0;
		for (int j = 0; j < N; ++j) {
			scanf("%d", &angka);
			bool pernah_masuk = false, sukses = false;
			for (int k = 10; k >= 0; --k) {
				for (int l = k; l >= 0; --l) {
					int temp = angka - k - l;
					if (temp < 0) continue;
					int kombinasi1 = abs(temp - k);
					int kombinasi2 = abs(temp - l);
					int kombinasi3 = abs(k - l);
					if (k >= p) {
						if (kombinasi1 < 2 && kombinasi2 < 2 && kombinasi3 < 2) {
							ans++;
							sukses = true;
							goto hell;
						}
						if (kombinasi1 <= 2 && kombinasi2 <= 2 && kombinasi3 <= 2) {
							pernah_masuk = true;
						}	
					}
					else {
						goto hell;
					}
				}
			}
			hell: ;
			if (pernah_masuk && !sukses && S > 0) {
				ans++;
				S--;
			}
		}
		printf("Case #%d: %d\n", i + 1, ans);
	}
}
