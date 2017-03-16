#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int a[20];
int aq[20];

int gcd(int a, int b)
{
    while (a && b) {
        int c = a % b;
        a = b;
        b = c;
    }
    return max(1, a | b);
}


int solve(int p, int q)
{
    int k = 0;
    while ((1 << k) != q && k < 30) {
        ++k;
    }
    if ((1 << k) != q) {
        return -1;
    }
    if (p > q) {
        return -1;
    }

    int pp = 1;
    while ((pp << 1) <= p) {
        pp <<= 1;
    }
    int qq = q / pp;
    int d = 0;
    while (qq > 1) {
        ++d;
        qq >>= 1;
    }
    return d;
    /*
    for (int n = 1; n < 11; ++n) {
        int nn = 1 << n;
        int nmask = 1 << nn;
        for (int mask = 0; mask < nmask; ++mask) {
            for (int i = 0; i < nn; ++i) {
                a[i] = (mask & (1 << i)) ? 1 : 0;
                aq[i] = 1;
            }

            int m = nn;
            while (m > 1) {
                m >>= 1;
                for (int j = 0; j < m; ++j) {
                    int p = a[j << 1] * aq[(j << 1) + 1] + aq[j << 1] * a[(j << 1) + 1];     
                    int q = 2 * aq[j << 1] * aq[(j << 1) + 1];
                    int g = gcd(p, q);
                    p /= g;
                    q /= g;
                    a[j] = p;
                    aq[j] = q;
                }
            }
            //cout << n << ": " << a[0] << "/" << aq[0] << endl;
            if (a[0] == p && aq[0] == q) {
                return n;
            }
        }
    }
    return -1;
    */
}

int main()
{
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        int p, q;
        scanf("%d/%d\n", &p, &q);
        int res = solve(p, q);
        if (res == -1) {
            printf("Case #%d: impossible\n", i + 1);
        }
        else {
            printf("Case #%d: %d\n", i + 1, res);
        }
    }
    
    return 0;
}
