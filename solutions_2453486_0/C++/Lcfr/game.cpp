#include <cstdio>
#include <cstdlib>

inline bool equal(const char ch, const char symbol) {
        return (ch == symbol || ch == 'T');
}

bool check(const char board[4][5], const char symbol) {
        for (int i = 0; i < 4; ++i) {
                int cntrow = 0, cntcol = 0;
                for (int j = 0; j < 4; ++j) {
                        if (equal(board[i][j], symbol))
                                ++cntrow;
                        if (equal(board[j][i], symbol))
                                ++cntcol;
                }
                if (cntrow == 4 || cntcol == 4)
                        return true;
        }
        int cntdiag1 = 0, cntdiag2 = 0;
        for (int i = 0, j = 0, k = 3; i < 4; ++i, ++j, --k) {
                if (equal(board[i][j], symbol))
                        ++cntdiag1;
                if (equal(board[i][k], symbol))
                        ++cntdiag2;
        }
        if (cntdiag1 == 4 || cntdiag2 == 4)
                return true;
        return false;
}

int main() {
        FILE *fin, *fout;
        fopen_s(&fin, "A-small-attempt0.in", "r");
        fopen_s(&fout, "A-small-attempt0.out", "w");
        int T;
        fscanf_s(fin, "%d", &T);
        for (int casenum = 1; casenum <= T; ++casenum) {
                fprintf(fout, "Case #%d: ", casenum);
                char board[4][5];
                for (int i = 0; i < 4; ++i)
                        fscanf_s(fin, "%s", board[i], _countof(board[i]));
                if (check(board, 'X')) {
                        fprintf(fout, "X won\n");
                } else if (check(board, 'O')) {
                        fprintf(fout, "O won\n");
                } else {
                        bool filled = true;
                        for (int i = 0; i < 4 && filled; ++i)
                                for (int j = 0; j < 4 && filled; ++j)
                                        if (board[i][j] == '.')
                                                filled = false;
                        if (filled)
                                fprintf(fout, "Draw\n");
                        else
                                fprintf(fout, "Game has not completed\n");
                }
        }
        system("pause");
        return 0;
}