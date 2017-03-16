#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define N 1001

bool inherited[1001][1001]; // inherited[i][j] => i inherited from j
bool reached[N];
int queue[N + 2];
int qhead, qend;

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	int c;
	for (c = 0; c < t; ++c) {
		int n;
		scanf("%d", &n);
		// printf("n = %d\n", n);
		int i, j;
		// init
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				inherited[i][j] = false;
			}
		}
		for (i = 0; i < n; ++i) {
			int m;
			scanf("%d", &m);
			int x;
			while (m--) {
				scanf("%d", &x);
				x--;
				inherited[i][x] = true;
			}
		}
		// check each node
		bool found = false;
		for (i = 0; i < n; ++i) {
			// printf("checking node %d\n", i);
			// init
			for (j = 0; j < n; ++j) {
				reached[j] = false;
			}
			qhead = qend = 0;
			queue[qend++] = i;
			reached[i] = true;
			while (!found && qend > qhead) {
				assert(qhead >= 0 && qhead < n);
				int index = queue[qhead++];
				assert(index >= 0 && index < n);
				for (j = 0; j < n; ++j) {
					if (inherited[index][j]) {
						if (reached[j]) {
							found = true;
						} else {
							// printf("pushing %d\n", j);
							assert(qend >= 0 && qend < n);
							queue[qend++] = j;
							reached[j] = true;
						}
					}
				}
			}
			if (found) {
				break;
			}
		}
		printf("Case #%d: %s\n", c + 1, found ? "Yes" : "No");
	}
	return 0;
}
