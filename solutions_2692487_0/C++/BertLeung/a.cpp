#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	int* A = (int*)a;
	int* B = (int*)b;
	
	return (*A - *B);
}

int list[110];
int ans, n;

int dfs(int a, int i, int c)
{
    int b, d;
    if (i == n) return c;
    if (a > list[i]) {
        return dfs(a+list[i], i+1, c);
    }

    b = dfs(a, i+1, c+1);
    if (a <= 1) return b;
    d = 0;
    while (a <= list[i]) {
        d++;
        a += (a-1);
    }
    d = dfs(a+list[i], i+1, c+d);

    return (b < d)? b : d;
}

int main()
{
	int aa, nn, a, i;
	scanf("%d", &nn);
	for (aa = 1; aa <= nn; ++aa) {
		scanf("%d %d", &a, &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &list[i]);
		}
		qsort(list, n, sizeof(int), compare);
		ans = 0;
        /*
		for (i = 0; i < n; i++)
		{
			if (a > list[i]) {
				a += list[i];
			} else if (a*2-1 > list[i]) {
				a += (a-1) + list[i];
				ans++;
			} else {
				ans++;
			}
		}
        */
        ans = dfs(a, 0, 0);
		printf("Case #%d: %d\n", aa, ans);
	}
	return 0;
}
