#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

int aa[1005][2];
int n;
int cc[1005];
int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &aa[i][0], &aa[i][1]);
        }
        memset(cc, 0, sizeof(cc));
        int now = 0;
        int cnt = 0;
        int ans = 0;
        for (;;) {
            int a = -1, b = -1, c = -1;
            for (int i = 0; i < n; ++i) {
                if (cc[i] == 0 && now >= aa[i][1]) {
                    a = i; break;
                }
                if (cc[i] == 1 && now >= aa[i][1]) {
                    b = i;
                }
                if (cc[i] == 0 && now >= aa[i][0]) {
                    if (c < 0 || aa[i][1] > aa[c][1]) c = i;
                }
            }
            if (a >= 0) {
                now += 2; cc[a] = 2;
                cnt++;
            } else if (b >= 0) {
                now++; cc[b] = 2;
                cnt++;
            } else if (c >= 0) {
                now++; cc[c] = 1;
            } else {
                break;
            }
            ans++;
        }
        if (cnt < n) printf("Case #%d: Too Bad\n", ca);
        else printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
