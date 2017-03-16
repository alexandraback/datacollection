#include <cstdlib>
#include <cstdio>
#include <map>
#include <queue>
#include <string>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char d[] = {'E', 'N', 'W', 'S'};
int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int X, Y;
        scanf("%d%d\n", &X, &Y);
        map<pair<int, int>, int> visit;
        queue<pair<pair<int, int>, string> > que[2];
        que[0].push(make_pair(make_pair(0, 0), ""));
        string res;
        int curq = 0;
        int nxtq = 1;
        int depth = 1;
        while (true) {
            while (!que[curq].empty()) {
                pair<pair<int, int>, string> state = que[curq].front();
                que[curq].pop();
                int x = state.first.first;
                int y = state.first.second;
                if (visit[state.first] == 1) continue;
                visit[state.first] = 1;
                if (x == X && y == Y) {
                    res = state.second;
                    goto FINISH;
                }
                for (int k = 0; k < 4; ++k) {
                    int nx = x + depth * dx[k];
                    int ny = y + depth * dy[k];
                    pair<pair<int, int>, string> next = make_pair(make_pair(nx, ny), state.second + d[k]);
                    que[nxtq].push(next);
                }
            }
            curq = 1 - curq;
            nxtq = 1 - nxtq;
            depth += 1;
        }
FINISH:;
        printf("Case #%d: %s\n", t, res.c_str());
    }
    return 0;
}
