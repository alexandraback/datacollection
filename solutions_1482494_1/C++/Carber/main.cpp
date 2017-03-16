#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<int, char> PIC;
typedef pair<int, int>  PII;
#define MP make_pair

const int INF = 0x3f3f3f3f;
const int MAXN = 2048;
PII ar[MAXN];
bool vist[MAXN][2];

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T, N;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        scanf("%d", &N);
        memset(vist, false, sizeof(vist));
        for (int i = 0; i < N; ++i) {
            scanf("%d %d", &ar[i].first, &ar[i].second);
        }
        int now_start = 0, step = 0;
        for (int i = 0; now_start < 2 * N; ++i) {
            int pre = now_start; 
            for (int j = 0; j < N; ++j) {
                if (vist[j][0] || vist[j][1]) continue;
                if (now_start >= ar[j].second) {
                    now_start += 2; ++step; vist[j][0] = vist[j][1] = true;
                    break;
                }
            }
            if (pre != now_start) continue;
            for (int j = 0; j < N; ++j) {
                if (vist[j][0] && !vist[j][1]) {
                    if (now_start >= ar[j].second) {
                        now_start += 1; ++step; vist[j][1] = true;
                        break;
                    }
                }
            }
            if (pre != now_start) continue;
            /*for (int j = 0; j < N; ++j) {
                if (vist[j][0] || vist[j][1]) continue;
                if (now_start >= ar[j].first && now_start + 1 >= ar[j].second) {
                    now_start += 2; step += 2; vist[j][0] = vist[j][1] = true; ++i;
                    break;
                }
            }*/
            if (pre != now_start) continue;
            int index = -1;
            for (int j = 0; j < N; ++j) {
                if (!vist[j][0]) {
                    if (now_start >= ar[j].first) {
                        if (index == -1 || ar[j].second > ar[index].second) {
                            index = j;
                        }
                    }
                }
            }
            if (index != -1) {
                ++now_start; ++step; vist[index][0] = true;
            } else  break;
        }
        if (now_start != 2 * N) {
            printf("Case #%d: Too Bad\n", cas);
        } else {
            printf("Case #%d: %d\n", cas, step);
        }
    }
    return 0;
}