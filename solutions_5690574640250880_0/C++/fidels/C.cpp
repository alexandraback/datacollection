#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int R, C, K, v[8][8];
char m[8][8];
bool done[8][8], FLAG, OUTPUT;

void check(int r, int c) {
    if (FLAG) return;

    int sr[32], sc[32], S=0, E=1, dr, dc, i, j;

    sr[0] = r; sc[0] = c; done[r][c] = true;
    while (S < E) {
        r = sr[S]; c = sc[S++];
        if (!v[r][c]) for (dr=-1; dr<=1; dr++) for (dc=-1; dc<=1; dc++) if (m[r+dr][c+dc] == '.' && !done[r+dr][c+dc]) {
            sr[E] = r+dr;
            sc[E++] = c+dc;
            done[r+dr][c+dc] = true;
        }
    }
    for (i=0; i<E; i++) done[sr[i]][sc[i]] = false;

    if (E == R*C-K) {
        FLAG = true;
        if (OUTPUT) {
            for (i=1; i<=R; i++) {
                for (j=1; j<=C; j++) {
                    if (i == sr[0] && j == sc[0]) cout << 'c';
                    else cout << m[i][j];
                }
                cout << endl;
            }
        }
    }
}

void dfs(int r, int c, int left) {
    if (FLAG) return;

    if (c == C+1) dfs(r+1, 1, left);
    else if (r == R+1) {
        if (!left) for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) if (m[i][j] == '.') check(i, j);
    } else {
        dfs(r, c+1, left);
        if (left) {
            m[r][c] = '*';
            for (int dr=-1; dr<=1; dr++) for (int dc=-1; dc<=1; dc++) if (dr!=0 || dc !=0) v[r+dr][c+dc]++;
            dfs(r, c+1, left-1);
            for (int dr=-1; dr<=1; dr++) for (int dc=-1; dc<=1; dc++) if (dr!=0 || dc !=0) v[r+dr][c+dc]--;
            m[r][c] = '.';
        }
    }
}

set< pair< pair<int, int>, int > > inv;

int main() {
    int T, t, i, j;

    OUTPUT = false;
    for (R=1; R<=5; R++) for (C=1; C<=5; C++) for (K=0; K<R*C; K++) {
        memset(v, 0, sizeof(v)); memset(done, false, sizeof(done)); FLAG = false;
        for (i=1; i<=R; i++) for (j=1; j<=C; j++) m[i][j] = '.';
        for (i=0; i<=R+1; i++) m[i][0] = m[i][C+1] = '#';
        for (j=0; j<=C+1; j++) m[0][j] = m[R+1][j] = '#';
        dfs(1, 1, K);
        if (!FLAG) inv.insert(make_pair(make_pair(R, C), K));
    }
    OUTPUT = true;

    cin >> T;
    for (t=1; t<=T; t++) {
        cin >> R >> C >> K;

        cout << "Case #" << t << ":" << endl;
        if (inv.find(make_pair(make_pair(R, C), K)) != inv.end()) cout << "Impossible" << endl;
        else {
            memset(v, 0, sizeof(v)); memset(done, false, sizeof(done)); FLAG = false;
            for (i=1; i<=R; i++) for (j=1; j<=C; j++) m[i][j] = '.';
            for (i=0; i<=R+1; i++) m[i][0] = m[i][C+1] = '#';
            for (j=0; j<=C+1; j++) m[0][j] = m[R+1][j] = '#';
            dfs(1, 1, K);
        }
    }

    return 0;
}
