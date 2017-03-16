#include <string>
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


#define N 105
#define mod 1000000007
#define LL long long

inline int read() {//used to read 32bit positive integer
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    int x = 0;
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }

    return x;
}

LL power(int a, int p) {
    LL res = 1;
    while (p) {
        if (p & 1) res = res * a;
        p >>= 1;
        a = a * a;
    }
    return res;
}

int main() {
    int test, k, c, n;
    scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        scanf("%d%d%d", &k, &c, &n);
        printf("Case #%d:", cas);
        if (c == 1) {
            if (n == k) {
                for (int i = 1; i <= k; i++) {
                    printf(" %d", i);
                }
                puts("");
            }
            else {
                puts(" IMPOSSIBLE");
            }
        }
        else {
            int lim = (k + 1) >> 1;
            if (n >= lim) {
                for (int i = 2; i <= k; i += 2) {
                    LL id = (i - 2) * power(k, c - 1) + i;
                    printf(" %lld", id);
                }
                if (k & 1) {
                    printf(" %lld", (k - 1) * power(k, c - 1) + 1);
                }
                puts("");
            }
            else {
                puts(" IMPOSSIBLE");
            }
        }
    }
    return 0;
}

