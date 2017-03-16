import fileinput

def read_list(fin, type):
    return list(map(type, next(fin).split()))

def problems(fin):
    T = int(next(fin))
    for _ in range(T):
        R, C, M = read_list(fin, int)
        yield R, C, M

def make_board(rows, cols, ch='.'):
    return [[ch for c in range(cols)] for r in range(rows)]

def draw_board(board):
    return "\n".join("".join(row) for row in board)

def solve_1(rows, cols, o):
    board = make_board(rows, cols, '*')
    for c in range(o):
        board[0][c] = '.'
    board[0][0] = 'c'
    return board

def solve_2(rows, cols, o):
    if o == 1:
        board = make_board(rows, cols, '*')
        board[0][0] = 'c'
        return board

    if o % 2 or o == 2:
        return None

    board = make_board(rows, cols, '*')
    for c in range(o // 2):
        board[0][c] = '.'
        board[1][c] = '.'
    board[0][0] = 'c'
    return board

def solve_n(rows, cols, o):
    if o == 1:
        board = make_board(rows, cols, '*')
        board[0][0] = 'c'
        return board

    if o in [2, 3, 5, 7]:
        return None

    if o > 2 * rows:
        board = make_board(rows, cols, '*')
        empty_cols = o // rows
        assert empty_cols >= 2

        for c in range(empty_cols):
            for r in range(rows):
                board[r][c] = '.'
        for r in range(o % rows):
            board[r][empty_cols] = '.'
        board[0][0] = 'c'

        if o % rows == 1:
            if empty_cols == 2:
                board[ 1][empty_cols    ] = '.'
                board[ 2][empty_cols    ] = '.'
                board[-1][empty_cols - 1] = '*'
                board[-1][empty_cols - 2] = '*'
            else:
                board[ 1][empty_cols    ] = '.'
                board[-1][empty_cols - 1] = '*'
        return board

    board = make_board(rows, cols, '*')
    for r in range(o // 2):
        board[r][0] = '.'
        board[r][1] = '.'
    if o % 2:
        board[0][2] = '.'
        r = o // 2 - 1
        board[1][2] = '.'
        board[2][2] = '.'
        board[r][0] = '*'
        board[r][1] = '*'

    board[0][0] = 'c'
    return board

def solve(problem):
    R, C, M = problem
    o = R * C - M
    assert o > 0
    assert R >= 1 and C >= 1
    # print("{} x {}, mines = {}, open = {}".format(R, C, M, o))

    rows, cols = min(R, C), max(R, C)
    board = None

    if rows == 1:
        board = solve_1(rows, cols, o)
    elif rows == 2:
        board = solve_2(rows, cols, o)
    else:
        board = solve_n(rows, cols, o)

    if not board:
        return "Impossible"

    if rows != R:
        board = [[board[c][r] for c in range(C)] for r in range(R)]
    return draw_board(board)

def main():
    for i, p in enumerate(problems(fileinput.input())):
        ans = solve(p)
        print("Case #{}:\n{}".format(i + 1, ans))

if __name__ == '__main__':
    main()