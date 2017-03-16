#include <memory.h>
#include <stdio.h>

struct _data {
	int a, b;
};

int n;
_data data[1010];

int check[1010];

bool end()
{
	int i;
	for (i=0; i<n; i++) if (check[i]!=2) return false;
	return true;
}

int main()
{
	int i, j;

	int t, tt=0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);

		for (i=0; i<n; i++) scanf("%d %d", &data[i].a, &data[i].b);

		memset(check, 0, sizeof(check));

		int stars = 0, round = 0;
		while (!end()) {
			for (j=0; j<n; j++) if (!check[j]) {
				if (data[j].b <= stars) {
					check[j] = 2;
					stars += 2;
					round ++;
					break;
				}
			}
			if (j<n) continue;

			for (j=0; j<n; j++) if (check[j]==1) {
				if (data[j].b <= stars) {
					check[j] = 2;
					stars ++;
					round ++;
					break;
				}
			}
			if (j<n) continue;

			int minx = -1;
			for (j=0; j<n; j++) if (!check[j]) {
				if (data[j].a <= stars) {
					if (minx==-1 || data[minx].b < data[j].b)
						minx = j;
				}
			}

			if (minx == -1) {
				round = -1;
				break;
			}

			round++;
			check[minx] = 1;
			stars ++;
		}

		printf("Case #%d: ", ++tt);
		if (round==-1) printf("Too Bad\n");
		else printf("%d\n", round);
	}

	return 0;
}
