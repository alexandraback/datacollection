//Problem C. Minesweeper Master
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("CJC.in", "r", stdin);
    freopen("CJC.out", "w", stdout);

    int T;
    cin >> T;
    for(int cse = 1; cse <= T; cse++) {
        cout << "Case #" << cse << ':' << endl;
        int R,C,M;
        cin >> R >> C >> M;

        char grid[R][C];
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                grid[i][j] = '*';

        int N = R*C - M;

        bool possible = false;

        for(int r = 1; r <= R && !possible; r++) {
            for(int c = 1; c <= C && !possible; c++) {
                int L = N - r*c, botL = 0, ritL = 0;

                if(r*c > N) continue;
                else if(r == 1 && R != 1 && N != 1) continue;
                else if(c == 1 && C != 1 && N != 1) continue;
                else if(r*c == N) {
                    possible = true;
                } else {
                    if(L == 1) continue;

                    if(r == R) {
                        if(L >= r) continue;
                        ritL = L;
                        possible = true;
                    } else if(c == C) {
                        if(L >= c) continue;
                        botL = L;
                        possible = true;
                    } else {
                        if(L >= r + c) continue;
                        for(int i = 0; i <= r && i <= L; i++) {
                            ritL = i;
                            botL = L - i;
                            if(ritL <= r && botL <= c && ritL != 1 && botL != 1) {
                                possible = true;
                                break;
                            }
                        }
                    }
                }

                if(possible) {
//                    cout << r << ':' << c << ' ' << botL << '/' << ritL << endl;
                    for(int i = 0; i < r; i++)
                        for(int j = 0; j < c; j++)
                            grid[i][j] = '.';

                    for(int i = 0; i < botL; i++)
                        grid[r][i] = '.';

                    for(int i = 0; i < ritL; i++)
                        grid[i][c] = '.';
                }
            }
        }

        grid[0][0] = 'c';
        if(possible)
            for(int i = 0; i < R; i++)
            {
                for(int j = 0; j < C; j++)
                    cout << grid[i][j];
                cout << endl;
            }
        else
            cout << "Impossible" << endl;
    }
}
