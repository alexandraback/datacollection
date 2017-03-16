#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

bool v[2000];
int prime[2000];
int m, N;
int ans[20], a[50];
int n = 32;

void seta(int x) {
    for (int i = 0; i < n - 2; ++i) {
        a[i+1] = (x >> i)&1;
    }
}

bool calc(int x) {
    seta(x);
    for (int i = 2; i <= 10; ++i) {
        bool flag = false;
        for (int j = 0; j < m; ++j) {
            int x = 0, d = 1;
            for (int k = 0; k < n; ++k) {
                x += d * a[k] % prime[j];
                d *= i;
                d %= prime[j];
                x %= prime[j];
            }
            if (x == 0) {
                ans[i] = prime[j];
                flag = true;
                break;
            }
        }
        if (!flag) return false;
    }
    for (int i = n-1; i >= 0; --i) printf("%d", a[i]);
    for (int i = 2; i <= 10; ++i) {
        printf(" %d", ans[i]);
    }
    printf("\n");
    return true;
}

int main() {
    m = 0;
    for (int i = 2; i <= 600; ++i) {
        if (!v[i]) {
            prime[m++] = i;
            for (int j = i; j <= 600; j += i) {
                v[j] = true;
            }
        }
    }
    freopen("C.out", "w", stdout);
    printf("Case #1:\n");
    N = 1 << (n-2);
    a[0] = 1;
    a[n-1] = 1;
    int ct = 500;
    for (int i = 0; i < N && ct; ++i) {
        if (calc(i)) ct--;
        
    }
}