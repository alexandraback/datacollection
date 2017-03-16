#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int R, C, M;

int r_idx[] = {-1, -1, -1, 0, 0, +1, +1, +1};
int c_idx[] = {-1, 0, +1, -1, +1, -1, 0, +1};

const int MINE = 999999;

vector<string> grid;

void init() {
    grid = vector<string>(R, string(C, '.'));
}

vector<vector<int>> get_num_grid(vector<string>& grid) {
    auto num_grid = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), 0));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == '*') {
                for (int k = 0; k < 8; ++k) {
                    int row = i + r_idx[k];
                    int col = j + c_idx[k];

                    if (row < 0 || row >= R || col < 0 || col >= C)
                        continue;

                    if (num_grid[row][col] == -1)
                        continue;

                    num_grid[row][col]++;
                }
                num_grid[i][j] = -1;
            }
        }
    }

    return num_grid;
}

void print(vector<vector<int>> grid) {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isPossible() {
    auto num_grid = get_num_grid(grid);
    int cnt_of_dot = 0;

    bool found_zero = false;
    queue<tuple<int, int>> q;

    tuple<int, int> only_dot;
    tuple<int, int> zero_pos;

//    cout << "origin:" << endl;
 //   print(num_grid);

    for (int i = 0; i < R && found_zero == false; ++i) {
        for (int j = 0; j < C && found_zero == false; ++j) {
            if (grid[i][j] == '.') {
                cnt_of_dot++;
                only_dot = make_tuple(i, j);
            }

            if (num_grid[i][j] == 0) {
                found_zero = true;
                num_grid[i][j] = -1;
                zero_pos = make_tuple(i, j);
                q.push(make_tuple(i, j));
            }
        }
    }

    if (found_zero == false) {
        if (cnt_of_dot == 1) {
            //cout << "cnt is one:" << endl;
            //print(num_grid);
            grid[get<0>(only_dot)][get<1>(only_dot)] = 'c';
            return true;
        }
        return false;
    }

    while (!q.empty()) {
        auto pos = q.front();
        q.pop();

        int i = get<0>(pos);
        int j = get<1>(pos);

        for (int k = 0; k < 8; ++k) {
            int row = i + r_idx[k];
            int col = j + c_idx[k];

            if (row < 0 || row >= R || col < 0 || col >= C)
                continue;

            if (grid[row][col] == '.' && num_grid[row][col] == 0)
                q.push(make_tuple(row, col));

            num_grid[row][col] = -1;
        }
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (num_grid[i][j] != -1)
                return false;
        }
    }

    //cout << "last: " << endl;
   // print(num_grid);
    grid[get<0>(zero_pos)][get<1>(zero_pos)] = 'c';
    return true;
}

bool solve(int mine_cnt, int r, int c) {
    if (mine_cnt == 0) {
        return isPossible();
    }

    if (r == R)
        return false;
    if (c == C)
        return solve(mine_cnt, r+1, 0);

    for (int i = r; i < R; ++i) {
        for (int j = c; j < C; ++j) {
            if (grid[i][j] == '*')
                continue;

            grid[i][j] = '*';
            if (solve(mine_cnt - 1, i, j+1))
                return true;

            grid[i][j] = '.';
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; ++testCase) {
        cin >> R >> C >> M;

        printf("Case #%d:\n", testCase);

        init();
        if (!solve(M, 0, 0)) {
            cout << "Impossible" << endl;
        }
        else {
            for (const auto& str : grid)
                cout << str << endl;
        }
    }

    return 0;
}
