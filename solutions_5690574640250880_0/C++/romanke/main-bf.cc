#include <iostream>
#include <vector>
#include <algorithm>

// note: 
// for lack of time currently, we begin with a bruteforce solution,
// which I expect to improve when I have the time.
// it should suffice due to low dimensions of the small dataset.

static const char empty = '.';
static const char bomb = '*';
static const char click = 'c';
static const char close_to_bomb = 'b';
static const char visited = 'v';

static void dfs (std::vector< std::vector<char> > &board, size_t row, size_t col) {
    if (row < 1 || row >= board.size()-1 || col < 1 || col >= board[row].size()-1)
        return;

    bool was_empty = (board[row][col] == empty);
    board[row][col] = visited;
    
    if (was_empty)
        for (int ki=-1; ki<2; ki+=1)
            for (int kj=-1; kj<2; kj+=1)
                dfs(board, row+ki, col+kj);
}

static inline bool all_reachable (std::vector< std::vector<char> > &board, size_t row, size_t col) {
    dfs(board, row, col);
    for (size_t i=1; i<board.size()-1; ++i)
        for (size_t j=1; j<board[i].size()-1; ++j)
            if (board[i][j] != bomb && board[i][j] != visited)
                return false;
    return true;
}

static inline bool find_click (std::vector<char> &orig_board, size_t rows, size_t cols, size_t bombs) {
    // construct a board with dummies
    std::vector< std::vector<char> > board;
    board.push_back(std::vector<char>(cols+2, empty));
    for (size_t i=0; i<rows; ++i) {
        std::vector<char> row(cols+2, empty);
        for (size_t j=0; j<cols; ++j)
            row[j+1] = orig_board[i*cols + j];
        board.push_back(row);
    }
    board.push_back(std::vector<char>(cols+2, empty));

    // mark close to bombs
    for (size_t i=1; i<=rows; ++i)
        for (size_t j=1; j<=cols; ++j)
            if (board[i][j] == bomb) {
                for (int ki=-1; ki<2; ki+=1)
                    for (int kj=-1; kj<2; kj+=1)
                        if (board[i+ki][j+kj] != bomb)
                            board[i+ki][j+kj] = close_to_bomb;
            }

    // find empty spot
    for (size_t i=1; i<=rows; ++i)
        for (size_t j=1; j<=cols; ++j)
            if (all_reachable(board, i, j)) {
                orig_board[(i-1)*cols + j-1] = click;
                return true;
            }
            else
                return false;

    // if empty not found
    if (rows*cols - bombs > 1)
        return false;
    for (size_t i=0; i<rows*cols; ++i)
        if (orig_board[i] != bomb)
            orig_board[i] = click;
    return true;
}

static inline void solve (size_t rows, size_t cols, size_t bombs) {
    std::vector<char> board(rows * cols, empty);
    for (size_t i=0; i<bombs; ++i)
        board[i] = bomb;
    std::sort(board.begin(), board.end());
    
    do {
        if (find_click(board, rows, cols, bombs)) {
            for (size_t i=0; i<rows; ++i) {
                for (size_t j=0; j<cols; ++j)
                    std::cout << board[cols*i + j];
                std::cout << std::endl;
            }
            return;
        }
    } while (std::next_permutation(board.begin(), board.end()));

    std::cout << "Impossible" << std::endl;
}

void play (size_t caseidx) {
    size_t r, c, m;
    std::cin >> r >> c >> m;

    std::cout << "Case #" << caseidx << ":" << std::endl;
    solve(r, c, m);
}

int main () {
    size_t cases;
    std::cin >> cases;
    for (size_t i=1; i<=cases; ++i)
        play(i);

    return 0;
}
