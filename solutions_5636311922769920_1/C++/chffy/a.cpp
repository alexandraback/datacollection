#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        int K, C, S;
        scanf("%d%d%d", &K, &C, &S);
        static int ca = 0;
        printf("Case #%d: ", ++ca);
        if (C * S < K) {
            puts("IMPOSSIBLE");
            continue;
        }
        vector<LL> ver;
        int mark = 0;
        while (mark < K) {
            LL x = 0;
            for (int i = 1; i <= C; ++i) {
                int y = mark;
                if (mark == K) {
                    y = K - 1;
                }
                else ++mark;
                x = x * K + y; 
            }
            ++x;
            ver.push_back(x);
        }
        for (int i = 0; i < ver.size(); ++i)
            printf("%I64d%c", ver[i], " \n"[i + 1 == ver.size()]);
    }
}
