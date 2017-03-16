#include <iostream>

using namespace std;

int T, M, R, C, S;
char board[50][50];

int main() {
    freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":" << endl;
        cin >> R >> C >> M;
        S = R * C - M;
        if (R == 1) {
            cout << "c";
            for(int i = 0; i < C - M - 1; i++)
                cout << ".";
            for(int i = 0; i < M; i++)
                cout << "*";
            cout << endl;
        } else if (C == 1) {
            cout << "c" << endl;
            for(int i = 0; i < R - M - 1; i++)
                cout << "." << endl;
            for(int i = 0; i < M; i++)
                cout << "*" << endl;
        } else if (S == 1) {
            for(int i = 0; i < R; i++) {
                for(int j = 0; j < C; j++)
                    if (i == 0 && j == 0)
                        cout << "c";
                    else
                        cout << "*";
                cout << endl;
            }
        } else if (S < 4 || S == 5 || S == 7) {
            cout << "Impossible" << endl;
        } else {
            for(int i = 0; i < R; i++)
                for(int j = 0; j < C; j++)
                    board[i][j] = '*';
            bool flag = 0;
            for(int i = 2; i <= R; i++) {
                for(int j = 2; j <= C; j++) {
                    if (i == 2 && i * j == S) {
                        for(int k = 0; k < j; k++)
                            board[0][k] = board[1][k] = '.';
                        flag = 1;
                        break;
                    } else if (j == 2 && i * j == S) {
                        for(int k = 0; k < i; k++)
                            board[k][0] = board[k][1] = '.';
                        flag = 1;
                        break;
                    } else if (i > 2 && j > 2 && i * j >= S && (i + j - 2) * 2 <= S) {
                        for(int k = 0; k < j; k++)
                            board[0][k] = board[1][k] = '.';
                        for(int k = 0; k < i; k++)
                            board[k][0] = board[k][1] = '.';
                        S -= (i + j - 2) * 2;
                        for(int k = 2; k < i; k++)
                            for(int l = 2; l < j; l++)
                                if (S > 0) {
                                    board[k][l] = '.';
                                    S--;
                                }
                        flag = 1;
                        break;
                    }
                }
                if (flag) break;
            }
            board[0][0] = 'c';
            if (flag) {
                for(int i = 0; i < R; i++) {
                    for(int j = 0; j < C; j++)
                        cout << board[i][j];
                    cout << endl;
                }
            } else {
                cout << "Impossible" << endl;
            }
        }
    }
    //system("pause");
    return 0;
}
