#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int T;
int a, n;
int num[100];
int add[100];

int cmp(const void * n1, const void * n2) {
    return *((int *)n1) - *((int *)n2);
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    scanf("%d", &T);
    for (int ti = 1; ti <= T; ++ti) {
        scanf("%d %d", &a, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &num[i]);
        }
        qsort(num, n, sizeof(num[0]), cmp);
        for (int i = 0; i < n; ++i) {

            if (a == 1) {
                add[i] = 999999999;
            } else {
                if ( i == 0) {
                    add[i] = 0;
                } else {
                    add[i] = add[i - 1];
                }
                while ( a <= num[i]) {
                    a = a + (a - 1);
                    ++add[i];
                }
                a = a + num[i];
            }
        }
        int ans = n;
        for (int i = 1; i <= n; ++i) {

            if (add[i - 1] + n - i < ans) {
                ans = add[i - 1] + n - i;
            }
        }
        printf("Case #%d:", ti);
        printf(" %d\n", ans);
    }

    return 0;
}

