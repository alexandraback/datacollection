#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define REP(a, b) for (int a = 0; a < b; ++a)
#define FORU(a, b, c) for (int a = b; a <= c; ++a)
#define FORD(a, b, c) for (int a = b; a >= c; --a)
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

int C, D, V, T, coin[11], dua[6];
bool sukses[1005], baru[1005], pilih[55];

int solusiSatu() {
	memset(sukses, false, sizeof(sukses));

	REP(i, 1 << D) {
		int temp = 0;

		REP(j, D) {
			if (i & (1 << j)) {
				temp += coin[j];
			}
		}

		sukses[temp] = true;
	}

	sukses[0] = true;
	// FORU(i, 1, V) {
	// 	if (sukses[i])
	// 		printf("%d ", i);
	// }
	// printf("\n");
	int ans = 0;

	FORU(i, 1, V) {
		if (!sukses[i]) {
			int tambah;

			FORD(j, 4, 0) {
				if (dua[j] > i) {
					continue;
				}

				if (pilih[dua[j]])
					continue;

				tambah = dua[j];
				break;
			}

			pilih[tambah] = true;

			++ans;
			memset(baru, false, sizeof(baru));

			if (i == tambah) {
				baru[tambah] = true;
				sukses[tambah] = true;
			}
			// sukses[i] = true;
			// baru[i] = true;

			FORU(j, 1, V) {
				if (sukses[j] && !baru[j] && !sukses[tambah+j]) {
					// printf("sukses %d\n", tambah+j);
					sukses[tambah+j] = true;
					baru[tambah+j] = true;
				}

				// if (sukses[j]) {
				// 	printf("%d ", j);
				// }
			}
			// puts("");
		}
	}

	return ans;
}

int solusiDua() {
	memset(sukses, false, sizeof(sukses));

	REP(i, 1 << D) {
		int temp = 0;

		REP(j, D) {
			if (i & (1 << j)) {
				temp += coin[j];
			}
		}

		sukses[temp] = true;
	}

	int ans = 0;

	FORU(i, 1, V) {
		if (!sukses[i]) {
			++ans;
			memset(baru, false, sizeof(baru));
			sukses[i] = true;
			baru[i] = true;

			FORU(j, 1, V) {
				if (sukses[j] && !baru[j] && !sukses[i+j]) {
					sukses[i+j] = true;
					baru[i+j] = true;
				}
			}
		}
	}

	return ans;
}

int main() {
	dua[0] = 1;
	dua[1] = 2;
	dua[2] = 4;
	dua[3] = 8;
	dua[4] = 16;

	scanf("%d", &T);

	FORU(tc, 1, T) {
		scanf("%d %d %d", &C, &D, &V);

		memset(pilih, false, sizeof(pilih));

		REP(i, D) {
			scanf("%d", &coin[i]);
			pilih[coin[i]] = true;
		}

		printf("Case #%d: %d\n", tc, min(solusiSatu(), solusiDua()));
	}

	return 0;
}
