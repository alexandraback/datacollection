#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
using namespace std;
#define LIM 400

int dp[501][LIM + 2][LIM + 2];
char prev[501][LIM + 2][LIM + 2];

int c(int coor) {
    return coor + LIM / 2;
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
string dirs = "SNWEX";

int main(int argc, char *argv[]) {
    int ntest;
    cin >> ntest;

    for (int test = 1; test <= ntest; test++) {
        int X, Y;
        cin >> X >> Y;

        memset(dp, 1, sizeof(dp));
        int inf = dp[0][0][0];
        dp[0][c(0)][c(0)] = 0;

        int i;
        for (i = 0; i < 500; i++) {
            if (dp[i][c(Y)][c(X)] != inf) break;
            for (int x = -LIM / 2; x <= LIM / 2; x++)
                for (int y = -LIM / 2; y <= LIM / 2; y++) {
                    if (dp[i][c(y)][c(x)] == inf) continue;
                    for (int d = 0; d < 4; d++) {
                        int xt = x + dx[d] * (i + 1),
                            yt = y + dy[d] * (i + 1);
                        if (abs(xt) > LIM / 2 || abs(yt) > LIM / 2) continue;
                        if (dp[i + 1][c(yt)][c(xt)] > dp[i][c(y)][c(x)] + 1) {
                            dp[i + 1][c(yt)][c(xt)] = dp[i][c(y)][c(x)] + 1;
                            prev[i + 1][c(yt)][c(xt)] = d;
                        }
                    }

                }

        }

        string res;

        for (int j = i; j > 0; j--) {
            int p = prev[j][c(Y)][c(X)];
            res += dirs[p];
            Y -= dy[p] * j;
            X -= dx[p] * j;
        }


        reverse(res.begin(), res.end());

        cout << "Case #" << test << ": " << res << endl;
    }

}
