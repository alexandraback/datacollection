#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <map>
#include <stack>

#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define REP(a,b) for(int a = 0; a < b; ++a)
#define FORU(a,b,c) for(int a = b; a <= c; ++a)
#define FORD(a,b,c) for(int a = b; a >= c; --a)
#define MOD 1000000000
#define MODLL 1000007LL
#define INF 2123123123
#define pb push_back
using namespace std;

int main() {
	int n, T, bff[1005], student[1005];

	scanf("%d", &T);

	FORU(tc, 1, T) {
		int ans = 1;

		scanf("%d", &n);

		FORU(i, 1, n) {
			scanf("%d", &bff[i]);
		}

		int maks = (1 << n) - 1;

		FORU(i, 1, maks) {
			int selected = 0;

			REP(j, n) {
				if (i & (1 << j)) {
					student[selected++] = j + 1;
				}
			}

			// printf("------------------------- %d\n", selected);

			do {
				// REP(j, selected) {
				// 	printf("%d ", student[j]);
				// }
				// printf("\n");
				bool oke = true;

				REP(j, selected) {
					int left = j - 1;
					int right = j + 1;

					if (left < 0) {
						left += selected;
					}

					if (right == selected) {
						right = 0;
					}

					if (student[left] != bff[student[j]] && student[right] != bff[student[j]]) {
						oke = false;
						break;
					}
				}

				if (oke) {
					ans = max(ans, selected);
				}
			} while (next_permutation(student + 1, student + selected));
		}

		printf("Case #%d: %d\n", tc, ans);
	}

	return 0;
}
