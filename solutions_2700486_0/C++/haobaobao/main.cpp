#include <iostream>
#include <cstdio>

using namespace std;

int T;
int n, x, y;
double rate;

double c(int a, int b) {
    if (b == 0)
        return 1;
    return c(a - 1, b - 1) * a / b;

}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    scanf("%d", &T);
    for (int ti = 1; ti <= T; ++ti) {
        scanf("%d %d %d", &n, &x, &y);
        if (x < 0) {
            x = -x;
        }
        int i = 0;
        while (n - i - i - 1 > 0) {
            n = n - i - i - 1;
            i += 2;
        }
        printf("Case #%d: ", ti);
        if ( x + y < i) {
            printf("1.0\n");
        } else if (x + y > i) {
            printf("0.0\n");
        } else {
            rate = 0.0;
            for (int j = 0; j <= n; ++j) {
                int left = n - j;
                int right = j;
                if (left > i) {
                    right += left - i;
                    left = i;
                }
                if (right > i) {
                    left += right - i;
                    right = i;
                }
                if (left == i + 1 && right == i) {
                    ++ right;
                    -- left;
                }
                if (right > y) {
                    rate += c(n, j);
                }
            }
            for (int j = 0; j < n; ++j) {
                rate /= 2;
            }
            printf("%.8lf\n", rate);
        }
    }

    return 0;
}

