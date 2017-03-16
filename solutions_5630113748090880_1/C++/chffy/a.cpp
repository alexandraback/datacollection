#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1005;

int num[N * 3];

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(num, 0, sizeof(num));
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n * 2 - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int x;
                scanf("%d", &x);
                num[x] ^= 1;
            }
        }
        vector<int> ans;
        static int ca = 0;
        printf("Case #%d:", ++ca);
        for (int i = 0; i <= 2500; ++i)
            if (num[i]) {
                printf(" %d", i);
            }
        puts("");
    }
}
