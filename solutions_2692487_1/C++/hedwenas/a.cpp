#include<stdio.h>
#include<string.h>
#include<algorithm>

int DP[200][200];
int n, a, M[200];
int t;

void Min (int i, int j) {
	int steps = j;
	int size = DP[i][j];
	while (size <= M[i+1]) {
		steps ++;
		size += size - 1;
	}
	size += M[i+1];
	if (size > DP[i+1][steps])
		DP[i+1][steps] = size;
}

int main() {
	scanf ("%d", &t);
	int caze = 0;
	while (t --) {
		caze ++;
		memset (DP, -1, sizeof DP);
		memset (M, 0, sizeof M);
	
		scanf ("%d%d", &a, &n);
		
		n ++;
		for (int i = 1; i < n; i ++) {
			scanf ("%d", &M[i]);
		}
		
		std::sort (M, M + n);
		
		if (a == 1) {
			printf ("Case #%d: %d\n", caze, n-1);
			continue ;
		}
		
		DP[0][0] = a;
		for (int i = 0; i < n-1; i ++) {
			for (int j = 0; j <= n; j ++) {
				if (DP[i][j] == -1)
					continue ;
				Min (i, j);
			}
		}
		
		int ans = n;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				//printf ("%d ", DP[i][j]);
				if (DP[i][j] == -1)
					continue ;
				if (j + (n-i-1) < ans)
					ans = j + (n-i-1);
			}
			//printf ("\n");
		}
		
		printf ("Case #%d: %d\n", caze, ans);
	}
	return 0;
}
