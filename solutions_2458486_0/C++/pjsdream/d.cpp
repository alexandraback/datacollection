#include <stdio.h>
#include <memory.h>

int K, n;
int startkey[40];
int type[40];
int keycnt[40];
int key[40][40];

bool d[1048576];
int path[1048576][2];

int anspath[40];

int main()
{
	int t, tt=0;

	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);

	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &K, &n);

		for (int i=0; i<K; i++)
			scanf("%d", &startkey[i]), startkey[i]--;

		for (int i=0; i<n; i++) {
			scanf("%d%d", &type[i], &keycnt[i]), type[i]--;
			for (int j=0; j<keycnt[i]; j++)
				scanf("%d", &key[i][j]), key[i][j]--;
		}

		memset(d, 0, sizeof(d));
		d[(1<<n)-1] = true;
		for (int i=(1<<n)-1; i>=0; i--) if (d[i]) {
			for (int j=0; j<n; j++) if (i&(1<<j)) {
				int cnt=0;
				for (int k=0; k<K; k++) if (startkey[k]==type[j]) cnt++;
				for (int k=0; k<n; k++) if (j!=k) {
					if ((i&(1<<k)) && type[k]==type[j]) cnt--;
					if ((i&(1<<k))) for (int l=0; l<keycnt[k]; l++) if (key[k][l]==type[j]) cnt++;
				}

				if (cnt>=1) {
					if (!d[i-(1<<j)] || path[i-(1<<j)][1] > j) {
						path[i-(1<<j)][0] = i;
						path[i-(1<<j)][1] = j;
					}
					d[i-(1<<j)] = true;
				}
			}
		}

		printf ("Case #%d:", ++tt);
		if (d[0]) {
			for (int i=0, x=0; i<n; i++) {
				anspath[i] = path[x][1];
				x = path[x][0];
			}
			for (int i=0; i<n; i++)
				printf (" %d", anspath[i]+1);
			printf("%\n");
		}
		else printf (" IMPOSSIBLE\n");
	}

	return 0;
}