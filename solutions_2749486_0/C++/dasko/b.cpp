#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
#include <string>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

int d[40][1100][1100], g[40][1100][1100];

struct tri {
    int d; int x, y;
    tri (int _d = 0, int _x = 0, int _y = 0) : d(_d), x(_x), y(_y) {}
};

int find(int s) {
    int m = 2 * (int)sqrt(s) + 10, best = -1;
    //printf("%d -> %d\n", s, m);
    for (; m > 0 && m * (m + 1) / 2 >= s; --m) {
        int M = m * (m + 1) / 2;
        if (M % 2 == s % 2) {
            best = m;
        }
    }
    assert(best != -1);
    return best;
}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char name[] = "NESW";

int main(void) {
    int mx = 0;
    //for (int i = 0; i <= 2000000; ++i) {
     //   mx = max(mx, find(i));
    //}
    int M = 30;
    memset(d, 0, sizeof d);
    queue<tri> Q; Q.push(tri(0, 500, 500)); d[0][500][500] = 1;
    while (!Q.empty()) {
        tri t = Q.front(); Q.pop();
        tri tmp = t;
        if (t.d == M) {
            continue;
        }
        REP (dir, 4) {
            tmp  = t;
            ++tmp.d;
            tmp.x += dx[dir] * tmp.d;
            tmp.y += dy[dir] * tmp.d;
            if (!d[tmp.d][tmp.x][tmp.y]) {
                g[tmp.d][tmp.x][tmp.y] = dir;
                d[tmp.d][tmp.x][tmp.y] = 1;
                Q.push(tmp);
            }
        }
    }
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int X, Y; scanf("%d%d", &X, &Y);
        X += 500; Y += 500;
        int k = -1;
        for (int l = 0; l < M; ++l) {
            if (d[l][X][Y]) {
                k = l;
                break;
            }
        }
        assert(k != -1);
        string res;
        for (; k > 0; --k) {
            int dir = g[k][X][Y];
            res += string(1, name[dir]);
            X -= dx[dir] * k;
            Y -= dy[dir] * k;
        }
        reverse(ALL(res));
        printf("Case #%d: %s\n", t, res.c_str());
    }

    /*int N = 30;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int k = -1;
            for (int l = 0; l < M; ++l) {
                if (d[l][500 - i][500 - j]) {
                    k = l;
                    break;
                }
            }
            //printf("%d %d\n", k, i + j);
            //if (i + j > 0) assert(k == find(i + j));
            printf("%d ", k);
        }
        puts("");
    }*/
    return 0;
}

