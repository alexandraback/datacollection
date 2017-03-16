#include <stdio.h>



int map[1001][1001], check[1001][1001];

int main() {
	int t;

	scanf("%d", &t);

	int i;
	for(i = 0; i < t; i++) {
		int n, j;
		int count[1001] = {0, };

		int aa, bb;

		scanf("%d", &n);

		for(aa = 0; aa < n; aa++) {
			for(bb = 0; bb < n; bb++) {
				map[aa][bb] = check[aa][bb] = 0;
			}
		}

		for(j = 0; j < n; j++) {
			int m, k;
			scanf("%d", &m);
			
			for(k = 0; k < m; k++) {
				int number;
				scanf("%d", &number);
				map[j][number-1] = 1;
				count[number-1]++;
			}
		}

		int head =0;
		int tail = 0;
		int queue[1010][2];
		for(j = 0; j < n; j++) {
			if(count[j] == 0) {
				queue[tail][0] = j;
				queue[tail++][1] = j;
			}
		}

		while(head < tail) {
			int node = queue[head][0];
			int flag = queue[head][1];
			for(j = 0; j < n; j++) {
				if(map[node][j] == 1) {
					queue[tail][0] = j;
					queue[tail++][1] = flag;
					if(check[j][flag] == 0)
						check[j][flag] = 1;
					else {
						printf("Case #%d: Yes\n", i+1);
						break;
					}
				}
			}

			if(j != n)
				break;

			head++;
		}

		if(head == tail)
			printf("Case #%d: No\n", i+1);
	}

	return 0;
}