#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;

const int D = 2000;

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d%d", &n, &m);
    LL mask = (1LL << (n - 1)) + 1;
    freopen("a.out", "w", stdout);
    puts("Case #1:");
    while (m > 0) {
        vector<int> ver;
        //cout << 1 << endl;
        for (int i = 2; i <= 10; ++i) {
            for (int j = 2; j <= D; ++j) {
                LL p = 0;
                for (int k = n - 1; k >= 0; --k) {
                    p = p * i;
                    if (mask >> k & 1) ++p;
                    p %= j;
                }
                if (p == 0) {
                    ver.push_back(j);
                    break;
                }
            }
        }
        if (ver.size() == 9) {
            --m;
            for (int i = n - 1; i >= 0; --i)
                if (mask >> i & 1)
                    putchar('1');
                else putchar('0');
            for (int i = 0; i < 9; ++i)
                printf(" %d", ver[i]);
            puts("");
        }
        mask += 2;
    }
}
