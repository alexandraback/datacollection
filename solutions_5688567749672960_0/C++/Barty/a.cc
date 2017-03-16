#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int dist[1000000 + 9];
bool vst[1000000 + 9];
queue<int> q;
int rev(int x) {
    int num[10], len = 0;
    while (x) {
        num[len++] = x % 10;
        x /= 10;
    }
    int ret = 0;
    for (int i = len - 1, j = 1; i >= 0; --i, j *= 10) {
        ret += num[i] * j;
    }
    return ret;
}
int main() {
    memset(vst, 0, sizeof(vst));
    memset(dist, -1, sizeof(dist));
    q.push(1);
    vst[1] = true;
    dist[1] = 1;
    while (!q.empty()) {
        int now = q.front();
        int d = dist[now];
        q.pop();
        if (now + 1 <= 1000000) {
            if (!vst[now + 1]) {
                vst[now + 1] = true;
                dist[now + 1] = d + 1;
                q.push(now + 1);
            }
        }
        now = rev(now);
        if (now <= 1000000) {
            if (!vst[now]) {
                vst[now] = true;
                dist[now] = d + 1;
                q.push(now);
            }
        }
    }
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        int x;
        scanf("%d", &x);
        printf("Case #%d: %d\n", ca, dist[x]);
    }
    return 0;
}
