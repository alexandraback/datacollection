#include<stdio.h>
#include<stdlib.h>


int cmp(const void *a, const void *b) {
	if (*((int *)a) > *(int *)b) return 1;
	else if (*((int *)a) < *(int *)b) return -1;
	return 0;
}

int my_abs(int a) {
	return a>0 ? a : (-1)*a;
}

int main() {
	int T, nm= 1;
	scanf("%d", &T);
	int i, j, k;
	while (T--) {
		int a, b, k, ans= 0;
		scanf("%d%d%d", &a, &b, &k);
		for (i=0;i<a;i++) {
			for (j=0;j<b;j++) {
				//printf("i= %d, j= %d, aa= %d, k= %d\n", i, j, i&j, k);
				int tmp= i&j;
				if (tmp < k) ans++;
			}
		}
		
		
		printf("Case #%d: %d\n", nm++, ans);
	}
	return 0;
}
