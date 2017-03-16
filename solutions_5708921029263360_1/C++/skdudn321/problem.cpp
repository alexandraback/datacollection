#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int ans;

int main(void) {
	int T;
	int J, P, S, K;
	int i, j, k, l, tt;

	freopen("C-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		scanf("%d %d %d %d", &J, &P, &S, &K);
		int las = min(S, K); 
		ans = J * P * las;
		printf("Case #%d: %d\n", i, ans);

		for (j = 1; j <= J; j++) {
			l = j;
			for (k = 1; k <= P; k++) {
				for (tt = 1; tt <= las; tt++) {
					printf("%d %d %d\n", j, k, l);
					l = ((l % S) + 1);
				}
			}
		}
	}


}