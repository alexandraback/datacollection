#include <iostream>
#include <vector>
using namespace std;

#define min(a,b) ((a<b)?a:b)

void print(int R, int C, vector<vector<bool> >& grid)
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i == 0 && j == 0)
                cout << 'c';
            else
                cout << (grid[i][j] ? '*' : '.');
        }
        cout << endl;
    }
}

bool test(int R, int C, int M, vector<vector<bool> >& grid)
{
    if (M == 0)
        return true;
    else if (R <= 2 && C <= 2)
        return false;
    else if (R < C && M >= R) {
        for (int i = 0; i < R; i++)
            grid[i][C-1] = true;
        test(R, C-1, M-R, grid);
    }
    else if (R >= C && M >= C) {
        for (int i = 0; i < C; i++)
            grid[R-1][i] = true;
        test(R-1, C, M-C, grid);
    }
    else if (M <= R + C - 5 && R > 2 && C > 2) {
        int bottom = min(M, C-2), right = min(M-bottom, R-2);
        for (int i = 0; i < bottom; i++)
            grid[R-1][C-1-i] = true;
        for (int i = 0; i < right; i++)
            grid[R-2-i][C-1] = true;
        return (bottom + right == M);
    }
    else
        return false;
}

int main()
{
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int R, C, M;
        cin >> R >> C >> M;
        vector<vector<bool> > grid(R, vector<bool>(C, false));
        cout << "Case #" << c << ":" << endl;
        if (M == R*C-1) {
            vector<vector<bool> > sol(R, vector<bool>(C, true));
            print(R, C, sol);
        }
        else if (test(R, C, M, grid))
            print(R, C, grid);
        else
            cout << "Impossible" << endl;
    }
    return 0;
}
