#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> matrix_t;
typedef vector<char> row_t;

int dirs[4][2] = { {-1, 0}, {0, 1}, {0, -1}, {1, 0} };

vector<matrix_t> figures[7];

bool is_inside(const matrix_t& source, int r, int c) {
    return r >= 0 && r < (int)source.size() && c >= 0 && c < (int)source[0].size();
}

matrix_t extend_figure(const matrix_t& source, int new_r, int new_c) {
    matrix_t result;
    if (is_inside(source, new_r, new_c)) {
        result = source;
    } else if (new_r == -1) {
        result = matrix_t(1, row_t(source[0].size()));
        result.insert(result.end(), source.begin(), source.end());
        ++new_r;
    } else if (new_r == (int)source.size()) {
        result = source;
        result.push_back(row_t(source[0].size()));
    } else if (new_c == -1) {
        result = matrix_t(source.size(), row_t(1));
        for (size_t i = 0, size = source.size(); i != size; ++i)
            result[i].insert(result[i].end(), source[i].begin(), source[i].end());
        ++new_c;
    } else if (new_c == (int)source[0].size()) {
        result = source;
        for (auto& row : result)
            row.push_back(0);
    } else {
        throw exception();
    }

    result[new_r][new_c] = 1;
    return result;
}

bool can_extend(const matrix_t& source, int new_r, int new_c) {
    if (is_inside(source, new_r, new_c))
        return source[new_r][new_c] == 0;

    for (int d = 0; d < 4; ++d) {
        int r = new_r + dirs[d][0], c = new_c + dirs[d][1];
        if (is_inside(source, r, c) && source[r][c] == 1)
            return true;
    }
    return false;
}

void print_figure(const matrix_t& figure, ostream& out) {
    for (const auto& row : figure) {
        for (int val : row)
            out << char('0' + val);
        out << '\n';
    }
}

void gen_figures() {
    figures[1].push_back(matrix_t(1, row_t(1, 1)));

    figures[2].push_back(matrix_t(2, row_t(1, 1)));
    figures[2].push_back(matrix_t(1, row_t(2, 1)));

    for (int N = 2; N < 6; ++N)
        for (const auto& figure : figures[N]) {
            int rows = figure.size(), cols = figure[0].size();
            for (int i = -1; i <= rows; ++i)
                for (int j = -1; j <= cols; ++j)
                    if (can_extend(figure, i, j))
                        figures[N + 1].push_back(extend_figure(figure, i, j));
        }
}

matrix_t rotate(const matrix_t& figure) {
    matrix_t result(figure[0].size(), row_t(figure.size()));
    for (size_t i = 0, si = figure.size(); i != si; ++i)
        for (size_t j = 0, sj = figure[i].size(); j != sj; ++j)
            result[j][si - 1 - i] = figure[i][j];
    return result;
}

int x, r, c;

int bfs(matrix_t& maze, int r0, int c0) {
    if (maze[r0][c0] == 1)
        return 0;
    int result = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(r0, c0));
    maze[r0][c0] = 1;
    while (!q.empty()) {
        ++result;
        auto p = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int r = p.first + dirs[i][0], c = p.second + dirs[i][1];
            if (!is_inside(maze, r, c))
                continue;
            if (maze[r][c] == 0) {
                maze[r][c] = 1;
                q.push(make_pair(r, c));
            }
        }
    }

    return result;
}

bool sucks(const matrix_t& figure, int r, int c) {
    if ((int)figure.size() > r || (int)figure[0].size() > c)
        return true;
    for (int r0 = 0, last_r0 = r - (int)figure.size(); r0 <= last_r0; ++r0)
        for (int c0 = 0, last_c0 = c - (int)figure[0].size(); c0 <= last_c0; ++c0) {
            matrix_t maze(r, row_t(c));
            for (size_t i = 0, si = figure.size(); i != si; ++i)
                for (size_t j = 0, sj = figure[i].size(); j != sj; ++j)
                    maze[r0 + i][c0 + j] = figure[i][j];
            bool pos_sucks = false;
            for (size_t i = 0, si = maze.size(); i != si && !pos_sucks; ++i)
                for (size_t j = 0, sj = maze[i].size(); j != sj; ++j)
                    if (bfs(maze, i, j) % x != 0) {
                        pos_sucks = true;
                        break;
                    }
            if (!pos_sucks)
                return false;
        }

    return true;
}

bool solve() {
   if (x >= 7 || (x > r && x > c) || r * c % x != 0)
        return true;

    r = min(r, 8);
    c = min(c, 8);
    if (x < 3 || (x + 2 <= r && x + 2 <= c))
        return false;

    for (const auto& figure : figures[x])
        if (sucks(figure, r, c) && sucks(rotate(figure), r, c)) {
            return true;
        }

    return false;
}

int main() {
    gen_figures();

    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        cin >> x >> r >> c;
        cout << "Case #" << t << ": " << (solve() ? "RICHARD" : "GABRIEL") << '\n';
    }

    return 0;
}

