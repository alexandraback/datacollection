#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

inline bool check(int i, int M) {
    int cnt = 0;
    while (i > 0) {
        if (i & 2) {
            cnt++;
        }
        i >>= 1;
    }
    return cnt == M;
}

int f[30];
int main() {
    freopen("C.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    int cas = 0;
    while (T--) {
        int R, C, M;
        scanf("%d%d%d", &R, &C, &M);
        bool solved = false;
        for (int i = 0; i < (1 << (R * C)); i++) {
            if (solved) {
                break;
            }
            if (!check(i, M)) {
                continue;
            }
            queue <int> q;
            for (int j = 0; j < R * C; j++) {
                if (solved) {
                    break;
                }
                if ((1 << j) & i) {
                    continue;
                }
                while (!q.empty()) q.pop();
                q.push(j);
                memset(f, false, sizeof(f));
                f[j] = true;
                int cnt = 1;
                while (!q.empty()) {
                    int r = q.front() / C;
                    int c = q.front() % C;
                    q.pop();
                    bool flag = false;
                    for (int dx = -1; dx <= 1 && !flag; dx++)
                        for (int dy = -1; dy <= 1 && !flag; dy++) {
                            if (dx == 0 && dy == 0) continue;
                            int r1 = r + dx;
                            int c1 = c + dy;
                            if (r1 < 0 || r1 >= R || c1 < 0 || c1 >= C) {
                                continue;
                            }
                            int idx = r1 * C + c1;
                            if (i & (1 << idx)) {
                                flag = true;
                                break;
                            }
                        }
                    if (!flag) {
                        for (int dx = -1; dx <= 1; dx++)
                            for (int dy = -1; dy <= 1; dy++) {
                                if (dx == 0 && dy == 0) continue;
                                int r1 = r + dx;
                                int c1 = c + dy;
                                if (r1 < 0 || r1 >= R || c1 < 0 || c1 >= C) {
                                    continue;
                                }
                                int idx = r1 * C + c1;
                                if (!f[idx]) {
                                    f[idx] = true;
                                    cnt++;
                                    q.push(idx);
                                }
                            }
                    }
                }
                if (cnt == R * C - M) {
                    solved = true;
                    printf("Case #%d:\n", ++cas); 
                    for (int xx = 0; xx < R; putchar('\n'), xx++)
                        for (int yy = 0; yy < C; yy++) {
                            int idx = xx * C + yy;
                            if (idx == j) putchar('c');
                            else if ((1 << idx) & i) putchar('*');
                            else putchar('.');
                        }
                }
            }
        }
        if (!solved) {
            printf("Case #%d:\nImpossible\n", ++cas);
        }
    }
}
