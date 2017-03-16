#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
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

int dx[] = {0,1,1,-1}, dy[] = {1,1,0,1};

char board[4][4];

string comp() {
    REP (i, 4) {
        REP (j, 4) {
            REP (k, 4) {
                int xc = 0, oc = 0;
                for (int z = 0; ; ++z) {
                    int a = i + dx[k] * z;
                    int b = j + dy[k] * z;
                    if (a < 0 || a >= 4 || b < 0 || b >= 4) {
                        break;
                    }
                    if (board[a][b] == 'O' || board[a][b] == 'T') {
                        ++oc;
                    }
                    if (board[a][b] == 'X' || board[a][b] == 'T') {
                        ++xc;
                    }
                }
                if (xc == 4) {
                    return "X won";
                }
                if (oc == 4) {
                    return "O won";
                }
            }
        }
    }
    REP (i, 4) {
        REP (j, 4) {
            if (board[i][j] == '.') {
                return "Game has not completed";
            }
        }
    }
    return "Draw";
}

int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        REP (i, 4) {
            scanf("%s", board[i]);
        }
        printf("Case #%d: %s\n", t, comp().c_str());
    }
    return 0;
}

