#include <cstdio>

const int MAX_N = 1005;

int one_star[MAX_N];
int two_stars[MAX_N];
bool done[MAX_N][2];

int main() {
	int tests; scanf("%d", &tests);
	for (int t = 1; t <= tests; t++) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &one_star[i], &two_stars[i]);
			done[i][0] = done[i][1] = false;
		}

		int cnt = 0;
		int curr = 0;
		int ans = 0;

		while (cnt < n) {
			ans++;

			int chosen = -1;
			int level = -1;
			for (int i = 0; i < n; i++) if (!done[i][1]) {
				if (curr >= two_stars[i] && !done[i][0]) {
					chosen = i;
					level = 1;
					break;
				}

				if (curr >= two_stars[i]) {
					chosen = i;
					level = 1;
				}
				else if (!done[i][0] && curr >= one_star[i] && level != 1) {
					if (level == -1 || two_stars[chosen] < two_stars[i]) {
						level = 0;
						chosen = i;
					}
				}
			}

			if (chosen == -1)
				break;

			if (level == 0) {
				done[chosen][0] = true;
				curr++;
			}
			else {
				cnt++;

				if (done[chosen][0])
					curr++;
				else
					curr += 2;
				done[chosen][0] = done[chosen][1] = true;
			}
		}

		printf("Case #%d: ", t);
		if (cnt == n)
			printf("%d\n", ans);
		else
			printf("Too Bad\n");
	}

	return 0;
}
