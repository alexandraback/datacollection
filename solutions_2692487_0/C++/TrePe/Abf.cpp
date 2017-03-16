#include <stdio.h>
#include <algorithm>
using namespace std;

int cases, kejs;
int i, j, n;
int A;
int a[100];
int added[100];
int res;

int main() {
    scanf("%d", &cases);
    for (kejs = 1; kejs <= cases; kejs++) {
        printf("Case #%d: ", kejs);
        scanf("%d%d", &A, &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            added[i] = 0;
        }
        int aa = A;
        sort(a, a + n);
        if (A == 1) printf("%d\n", n);
        else {
            int best = 1212312;
            for (j = 0; j <= n; j++) {
                res = j;
                A = aa;
                for (i = 0; i < n-j; i++) {
                    while (a[i] >= A) {
                        res++;
                        A += A - 1;
                    }
	    			A += a[i];
                }
                if (res < best) best = res;
            }
            printf("%d\n", best);
        }
    }
    return 0;
}

