#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;

const char *answer[] = {"RICHARD", "GABRIEL"};
typedef vector<pair<int, int>> omino_t;
typedef vector<vector<char>> board_t;
vector<vector<omino_t>> ominoes;

int fill(board_t &board, int x, int y) {
    static const int dx[] = {0, -1, 0, 1};
    static const int dy[] = {-1, 0, 1, 0};
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
    assert(x <= 4);
    for (const omino_t &om: ominoes[x]) {
        if (!fit(om, r, c) and !fit(om, c, r))
            return false;
    }
    return true;
}

int main() {
    // 0, 1, 2 are special cases
    ominoes.resize(3);
    // 3
    ominoes.push_back({
            {{0, 0}, {0, 1}, {1, 0}},
            {{0, 0}, {0, 1}, {0, 2}}});
    // 4
    ominoes.push_back({
            {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
            {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
            {{0, 0}, {1, 0}, {1, 1}, {2, 0}},
            {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
            {{0, 0}, {1, 0}, {2, 0}, {3, 0}}});

    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        int x, r, c;
        scanf("%d%d%d", &x, &r, &c);
        printf("Case #%d: %s\n", cs, answer[solve(x, r, c)]);
    }
}
