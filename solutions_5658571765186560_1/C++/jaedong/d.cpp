#include <cstdio>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
using namespace std;

const char *answer[] = {"RICHARD", "GABRIEL"};
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
typedef set<pair<int, int>> omino_t;
typedef vector<vector<char>> board_t;
vector<vector<omino_t>> ominoes;

/// Generator

bool exists(const omino_t &om) {
    return count(ominoes[om.size()].begin(), ominoes[om.size()].end(), om);
}

omino_t rotate(const omino_t &om) {
    omino_t ret;
    for (auto p: om)
        ret.insert({p.second, p.first});
    return ret;
}

omino_t mirror_h(const omino_t &om) {
    int size_r = 0, size_c = 0;
    for (auto p: om) {
        size_r = max(size_r, p.first);
        size_c = max(size_c, p.second);
    }
    omino_t ret;
    for (auto p: om)
        ret.insert({size_r - p.first, p.second});
    return ret;
}
omino_t mirror_v(const omino_t &om) {
    int size_r = 0, size_c = 0;
    for (auto p: om) {
        size_r = max(size_r, p.first);
        size_c = max(size_c, p.second);
    }
    omino_t ret;
    for (auto p: om)
        ret.insert({p.first, size_c - p.second});
    return ret;
}

bool check(const omino_t &om) {
    if (exists(om) or exists(mirror_h(om)) or exists(mirror_v(om)) or exists(mirror_v(mirror_h(om))))
        return false;
    omino_t rot = rotate(om);
    if (exists(rot) or exists(mirror_h(rot)) or exists(mirror_v(rot)) or exists(mirror_v(mirror_h(rot))))
        return false;
    return true;
}

void generate(int x) {
    ominoes.resize(x + 1);
    for (auto &old_om: ominoes[x - 1]) {
        for (auto p: old_om) {
            for (int d = 0; d < 4; d++) {
                int nx = p.first + dx[d];
                int ny = p.second + dy[d];
                if (!old_om.count(make_pair(nx, ny))) {
                    int add_x = nx < 0 ? 1 : 0;
                    int add_y = ny < 0 ? 1 : 0;
                    omino_t new_om;
                    new_om.insert({nx + add_x, ny + add_y});
                    for (auto oldp: old_om)
                        new_om.insert({oldp.first + add_x, oldp.second + add_y});

                    if (check(new_om)) {
                        ominoes[x].push_back(new_om);
                    }
                }
            }
        }
    }
}


/// Solver

int fill(board_t &board, int x, int y) {
    board[x][y] = 1;
    int filled = 1;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (0 <= nx and nx < board.size() and 0 <= ny and ny < board[0].size()
            and board[nx][ny] == 0)
            filled += fill(board, nx, ny);
    }
    return filled;
}

bool ok(const omino_t &om, int i, int j, int r, int c) {
    board_t board(r, vector<char>(c, 0));
    for (auto p: om)
        board[i + p.first][j + p.second] = 1;
    for (int x = 0; x < r; x++)
        for (int y = 0; y < c; y++)
            if (board[x][y] == 0) {
                if (fill(board, x, y) % om.size() != 0)
                    return false;
            }
    return true;
}

bool fit(const omino_t &om, int r, int c) {
    int size_r = 0, size_c = 0;
    for (auto p: om) {
        size_r = max(size_r, p.first);
        size_c = max(size_c, p.second);
    }
    for (int i = 0; i + size_r < r; i++) {
        for (int j = 0; j + size_c < c; j++) {
            if (ok(om, i, j, r, c))
                return true;
        }
    }
    return false;
}

bool solve(int x, int r, int c) {
    if (x == 1)
        return true;
    if (x == 2)
        return (r * c) % 2 == 0;
    if (x >= 7)
        return false;
    for (const omino_t &om: ominoes[x]) {
        if (!fit(om, r, c) and !fit(om, c, r))
            return false;
    }
    return true;
}

int main() {
    ominoes.push_back({});
    ominoes.push_back({{{0, 0}}});
    generate(2);
    generate(3);
    generate(4);
    generate(5);
    generate(6);

    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        int x, r, c;
        scanf("%d%d%d", &x, &r, &c);
        printf("Case #%d: %s\n", cs, answer[solve(x, r, c)]);
    }
}
