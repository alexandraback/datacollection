#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int M, R, C;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct node {
    int r, c;
    int count;
    set<pair<int, int> > p;
};
set<set<pair<int, int> > > chk;
queue<node> q;
node ans;

int solve() {
    chk.clear();
    while (!q.empty()) {
        q.pop();
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            node t;
            t.r = i;
            t.c = j;
            t.p.insert(make_pair(i, j));
            t.count = 1;
            q.push(t);
            chk.insert(t.p);
        }
    }

    int dest = R * C - M;
    while (!q.empty()) {
        node t, t2;
        t = q.front(); q.pop();
        if (t.count == dest) {
            ans = t;
            return 1;
        }
        for (set<pair<int, int> >::iterator it = t.p.begin(); it != t.p.end(); ++it) {
            t2 = t;
            for (int i = 0; i < 8; ++i) {
                int r = dy[i] + it->first;
                int c = dx[i] + it->second;
                if (r < 0 || r >= R || c < 0 || c >= C) {
                    continue;
                }
                t2.p.insert(make_pair(r, c));
            }
            t2.count = t2.p.size();
            if (t2.count > dest) {
                continue;
            }
            if (chk.find(t2.p) == chk.end()) {
                chk.insert(t2.p);
                q.push(t2);
            }
        }
    }
    
    return 0;
}

char board[100][100];

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        printf("Case #%d:\n", cs);
        scanf("%d %d %d", &R, &C, &M);
        if (solve()) {
            fill(board[0], board[55], '*');
            for (set<pair<int, int> >::iterator it = ans.p.begin(); it != ans.p.end(); ++it) {
                board[it->first][it->second] = '.';
            }
            board[ans.r][ans.c] = 'c';
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) {
                    printf("%c", board[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}


