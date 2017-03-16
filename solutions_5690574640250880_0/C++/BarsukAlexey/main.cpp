#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <clocale>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

int test;
int dx[] = {-1, -1, -1, 0, 1, 1,  1, 0};
int dy[] = {-1,  0,  1, 1, 1, 0, -1, -1};
char fields[55][55];

void dfs(int rows, int cols, int i, int j) {
    if (fields[i][j] == '*') return;
    if (fields[i][j] == '!') return;
    if (i > rows || i < 1) return;
    if (j > cols || j < 1) return;
    bool was_mine = false;
    for (int k = 0; k < 8 && !was_mine; k++) {
        if (fields[i + dy[k]][j + dx[k]] == '*')
            was_mine = true;
    }
    if (was_mine) {
        fields[i][j] = '!';
    }
    else {
        fields[i][j] = '!';
        for (int k = 0; k < 8; k++)
            dfs(rows, cols, i + dy[k], j + dx[k]);
    }
}

bool was_solution(int rows, int cols, int mines, bool was = false) {

    if (rows < 1 || cols < 1) return false;
    if ((rows == 1 || cols == 1) && was) return false;

    int need_mines = mines;

    memset(fields, '.', sizeof(fields));

    rows -= 2;
    for (int j = 1; j <= rows; j++) {
        for (int k = 1; k <= cols && mines > 0; k++) {
            if (k == cols - 1 && mines == 1) {
                k++;
                continue;
            }
            fields[j][k] = '*';
            mines--;
        }
    }

    rows += 2;
    for (int j = 1; j <= cols; j++) {
        for (int k = rows - 1; k <= rows && mines > 0; k++) {
            while (k < 1) k++;
            fields[k][j] = '*';
            mines--;
        }
    }

    dfs(rows, cols, rows, cols);
    fields[rows][cols] = 'c';

    bool was_unopen = false;
    for (int j = 1; j <= rows; j++) {
        for (int k = 1; k <= cols && !was_unopen; k++) {
            if (fields[j][k] == '.')
                was_unopen = true;
        }
    }

    if (was_unopen) {
        if (need_mines - cols > 0 && was_solution(rows - 1, cols, need_mines - cols, true)) {
            for (int i = rows; i > 1; i--) {
                for (int j = cols; j >= 1; j--) {
                    fields[i][j] = fields[i - 1][j];
                }
            }
            for (int i = 1; i <= cols; i++) fields[1][i] = '*';
            return true;
        }
        if (need_mines - rows > 0 && was_solution(rows, cols - 1, need_mines - rows, true)) {
            for (int i = rows; i >= 1; i--) {
                for (int j = cols; j > 1; j--) {
                    fields[i][j] = fields[i][j - 1];
                }
            }
            for (int i = 1; i <= rows; i++) fields[i][1] = '*';
            return true;
        }
        return false;
    }
    else return true;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    ios_base::sync_with_stdio(false);
    cout << setprecision(8);

    cin >> test;
    for (int i = 0; i < test; i++) {
        int rows, cols, mines;
        cin >> rows >> cols >> mines;

        if (mines == rows*cols) {
            cout << "Case #" << i + 1 << ":" << endl;
            cout << "Impossible" << endl;
            cout.flush();
            continue;
        }

        cout << "Case #" << i + 1 << ":" << endl;
        if (!was_solution(rows, cols, mines, false)) {
            swap(rows, cols);
            if (!was_solution(rows, cols, mines, false)) {
                cout << "Impossible" << endl;
                cout.flush();
            }
            else {
                for (int j = 1; j <= cols; j++) {
                    for (int k = 1; k <= rows; k++) {
                        if (fields[k][j] == '!') fields[k][j] = '.';
                        cout << fields[k][j];
                    }
                    cout << endl;
                }
                cout.flush();
            }
        }
        else {
            for (int j = 1; j <= rows; j++) {
                for (int k = 1; k <= cols; k++) {
                    if (fields[j][k] == '!') fields[j][k] = '.';
                    cout << fields[j][k];
                }
                cout << endl;
            }
            cout.flush();
        }
    }

    return 0;
}
