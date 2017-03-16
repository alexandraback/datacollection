#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int i, j, k, kejsis, kejs, ret, n;
int a[1000], b[1000];
int gain[1000];
int has;

int main() {
	scanf("%d", &kejsis);
	for (int kejs = 1; kejs <= kejsis; ++kejs) {
		printf("Case #%d: ", kejs);
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d%d", &a[i], &b[i]);
			gain[i] = 0;
		}
		has = ret = 0;

cont:
		bool zmena;
		do {
			zmena = false;
			for (i = 0; i < n; i++) {
				if (gain[i] == 0) {
					if (b[i] <= has) {
						has += 2;
						gain[i] = 2;
						zmena = true;
						ret++;
					}
				}
			}
		} while (zmena);

		for (i = 0; i < n; i++) {
			if (gain[i] == 1) {
				if (b[i] <= has) {
					has += 1;
					gain[i] = 2;
					ret++;
					break;
				}
			}
		}
		if (i < n) goto cont;

		int m = -1, mi = -1;
		for (i = 0; i < n; i++) {
			if (gain[i] == 0) {
				if (a[i] <= has && b[i] > m) {
					mi = i; m = b[i];
				}
			}
		}
		if (mi != -1) {
			has += 1;
			gain[mi] = 1;
			ret++;
			goto cont;
		}


		for (i = 0; i < n; i++) if (gain[i] != 2) break;
		if (i < n) printf("Too Bad\n");
		else printf("%d\n", ret);
	}
	return 0;
}


