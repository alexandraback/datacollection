#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

const int multiply[4][4] =
{
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0}
};

const int sign[4][4] = 
{
    {0, 0, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 0, 1, 1}
};

int canget[8][8];
int inv[8];

int op(int i, int j) {
    int flag = 0;
    flag ^= (i & 1);
    i /= 2;
    flag ^= (j & 1);
    j /= 2;
    int res = multiply[i][j] * 2;
    res += (sign[i][j] ^ flag);
    return res;
}

void init() {
    memset(canget, 0, sizeof canget);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            canget[i][j] = op(i, j);
        }
    }
    for (int i = 0; i < 8; ++i) {
        for (inv[i] = 0; canget[i][inv[i]] != 0; ++inv[i]) {
            //fprintf(stderr, "%d %d %d\n", i, inv[i], canget[i][inv[i]]);
        }
    }
}

const int maxn = 10000 + 10;

int result[maxn], prefix[maxn], suffix[maxn];
int fullresult[maxn];
int X, L;
char str[maxn];

void solve() {
    scanf("%d%d", &L, &X);
    scanf("%s", str);
    prefix[0] = result[0] = 0;
    for (int i = 0; i < L; ++i) {
        switch (str[i]) {
            case 'i':
                result[i + 1] = canget[result[i]][1 * 2];
                break;
            case 'j':
                result[i + 1] = canget[result[i]][2 * 2];
                break;
            case 'k':
                result[i + 1] = canget[result[i]][3 * 2];
                break;
        }
        prefix[i + 1] = result[i + 1];
    }
    suffix[L] = 0;
    for (int i = L - 1; i >= 0; --i) {
        switch (str[i]) {
            case 'i':
                suffix[i] = canget[1 * 2][suffix[i + 1]];
                break;
            case 'j':
                suffix[i] = canget[2 * 2][suffix[i + 1]];
                break;
            case 'k':
                suffix[i] = canget[3 * 2][suffix[i + 1]];
                break;
        }
    }
    int turn = 0;
    fullresult[0] = 0;
    do {
        turn++;
        fullresult[turn] = canget[ fullresult[turn - 1] ][ result[L] ];
    } while (fullresult[turn] != 0);
    //fprintf(stderr, "%d\n", prefix[1]);
    //fprintf(stderr, "%d\n", suffix[2]);
    //fprintf(stderr, "%d\n", canget[ prefix[2] ][ inv[prefix[1]] ]);
    for (int x1 = 0; x1 < turn && x1 < X; ++x1) {
        for (int x2 = 0; x2 < turn && x1 + x2 < X; ++x2) {
            for (int x3 = 0; x3 < turn && x1 + x2 + x3 < X; ++x3) {
                for (int pos1 = 0; pos1 <= L; ++pos1) {
                    for (int pos2 = 0; pos2 <= L; ++pos2) {
                        // seg1
                        if (canget[ fullresult[x1] ][ prefix[pos1] ] != 1 * 2) {
                            continue;
                        }
                        // seg3
                        if (canget[ suffix[pos2] ][ fullresult[x3] ] != 3 * 2) {
                            continue;
                        }
                        // seg2
                        if (pos1 + 1 <= pos2 && (X - x1 - x2 - x3 - 1) % turn == 0) {
                            if (x2 == 0) {
                                if (canget[ inv[prefix[pos1]] ][ prefix[pos2] ] == 2 * 2) {
                                    puts("YES");
                                    return;
                                }
                            }
                        }
                        if (X >= x1 - x2 - x3 - 2 && (X - x1 - x2 - x3 - 2) % turn == 0) { 
                            if (canget[ suffix[pos1] ][ canget[ fullresult[x2] ][ prefix[pos2] ] ] == 2 * 2) {
                                puts("YES");
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    puts("NO");
}

int main() {
    //freopen("C.in", "r", stdin);
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C.out", "w", stdout);
    init();

    int testCount;
    scanf("%d", &testCount);
    for (int testId = 1; testId <= testCount; testId++) {
        printf("Case #%d: ", testId);
        solve();
    }
}
