#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testcase;
    scanf("%d", &testcase);
    for (int tt = 1; tt <= testcase; tt++) {
        int n;
        scanf("%d", &n);
        int m = 2*n-1;
        int a[2510];
        for (int i = 0; i < 2510; i++) {
            a[i] = 0;
        }
        int k;
        // cout << n * m;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &k);
                a[k]++;
            }
        }
        printf("Case #%d:", tt);
        for (int i = 0; i < 2510; i++) {
            if (a[i] % 2 == 1) {
                printf(" %d", i);
            }
        }
        printf("\n");
    }
    return 0;
}