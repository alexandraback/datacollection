#include "stdio.h"

int main ()
{
	int t;
	int i;

	scanf("%d", &t);

	for(i=0; i<t; i++) {
		int n,m,j;

		scanf("%d %d", &n, &m);
		
		int target[n][m];
		int state[n][m];

		for (j=0; j<n; j++) {
			int k;

			for (k=0; k<m; k++) {
				scanf("%d", &target[j][k]);
				state[j][k] = 100;
			}
		}

		for (j=0; j<n; j++) {
			int k;
			int max = 0;
			for (k=0; k<m; k++) {
				if (target[j][k] > max) {
					max = target[j][k];
				}
			}
			
			for (k=0; k<m; k++) {
				if (state[j][k] > max) {
					state[j][k] = max;
				}
			}
		}
		
		for (j=0; j<m; j++) {
			int k;
			int max = 0;
			for (k=0; k<n; k++) {
				if (target[k][j] > max) {
					max = target[k][j];
				}
			}
			
			for (k=0; k<n; k++) {
				if (state[k][j] > max) {
					state[k][j] = max;
				}
			}
		}

		int is_the_same = 1;
		
		for (j=0; j<n; j++) {
			int k;
			for (k=0; k<m; k++) {
				if (target[j][k] != state[j][k]) {
					is_the_same = 0;
					break;
				}
			}

			if (!is_the_same) {
				break;
			}
		}
		
		printf("Case #%d: %s\n", i+1, is_the_same?"YES":"NO");
	}

	return 0;
}
