#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;

string fi[18], la[18];

char str[23];

int main() {

	freopen("C-small-attempt2.in", "r", stdin);
	freopen("C-small-attempt2.out", "w", stdout);

	int t;
	scanf("%d", &t);

	int tc = 0;

	while (t--) {

		int n;
		scanf("%d", &n);

		map <string, int> A, B;

		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			fi[i] = string(str);
			scanf("%s", str);
			la[i] = string(str);
			A[fi[i]]++;
			B[la[i]]++;
		}

		map <string, bool> sA, sB;

		bool used[19] = { 0 };
		for (int i = 1; i <= n; i++) {
			if (A[fi[i]] == 1 || B[la[i]] == 1) {
				used[i] = true;
				sA[fi[i]] = sB[la[i]] = true;
			}
		}

		int fe = 0;
		for (int i = 1; i <= n; i++) {
			if (used[i])continue;
			if (sB[la[i]] && sA[fi[i]]) {
				fe++;
			}
		}

		printf("Case #%d: %d\n", ++tc, fe);

	}

}