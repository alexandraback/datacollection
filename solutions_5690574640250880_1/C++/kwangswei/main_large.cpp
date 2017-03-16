#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>

using namespace std;


int r_idx[] = {-1, -1, -1, 0, 0, +1, +1, +1};
int c_idx[] = {-1, 0, +1, -1, +1, -1, 0, +1};

int R, C, M;

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


bool isPossible(vector<string>& grid) {
    auto num_grid = get_num_grid(grid);
    int cnt_of_dot = 0;

    bool found_zero = false;
    queue<tuple<int, int>> q;

    tuple<int, int> only_dot;
    tuple<int, int> zero_pos;

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

    grid[get<0>(zero_pos)][get<1>(zero_pos)] = 'c';
    return true;
}

bool batch(int r, int c, int m, vector<string>& grid) {
    //printf("batch : (%d x %d) - %d\n", r, c, m);

    for (int k = 0; k < m; ++k) {
        bool found = false;
        for (int i = r; i < R && !found; ++i) {
            for (int j = c; j < C && !found; ++j) {
                if (grid[i][j] == '*')
                    continue;

                bool horizontal =  (i+1 < R && i+2 < R && grid[i+1][j] == '.' && grid[i+2][j] == '.');
                horizontal |= (i-1>=0 && i-2>=0 && grid[i-1][j] == '.' && grid[i-2][j] == '.');
                bool vertical = (j+1 < C && j+2 < C && grid[i][j+1] == '.' && grid[i][j+2] == '.');
                vertical |= (j-1>=0 && j-2>=0 && grid[i][j-1] == '.' && grid[i][j-2] == '.');

                if (horizontal == false || vertical == false)
                    continue;

                grid[i][j] = '*';
                found = true;
            }
        }

        if (!found)
            return false;
    }
    return isPossible(grid);
}

bool solve(int r, int c, int m, vector<string>& grid) {
    if (r == R || c == C)
        return false;

    if (m >= C-c && C-c < R-r) {
        grid[r] = string(C, '*');
        return solve(r+1, c, m-C+c, grid);
    }
    else if (m >= R-r) {
        for (int i = 0; i < R; ++i) {
            grid[i][c] = '*';
        }
        return solve(r, c+1, m-R+r, grid);
    }

    return batch(r, c, m, grid);
}

int main() {
    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; ++testCase) {
        cin >> R >> C >> M;

        printf("Case #%d:\n", testCase);

        vector<string> grid = vector<string>(R, string(C, '.'));

        if (!solve(0, 0, M, grid)) {
            cout << "Impossible" << endl;
        }
        else {
            for (const auto& str : grid)
                cout << str << endl;
        }
    }

    return 0;
}
