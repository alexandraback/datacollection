

def solve(rows, columns, mines):
    if mines >= rows * columns:
        return None
    if mines == rows * columns - 1:
        board = [['*'] * columns for i in range(rows)]
        board[0][0] = 'c'
        return board
        #else:
            #return None

    board = [['.'] * columns for i in range(rows)]
    board[0][0] = 'c'

    if mines == 0:
        return board

    remaining_mines = mines
    empty_rows = rows
    while remaining_mines >= columns and empty_rows > 3:
        remaining_mines -= columns
        empty_rows -= 1
        board[empty_rows] = ['*'] * columns

    if empty_rows > 3:
        #print('er+')
        if remaining_mines == 0:
            return board
        if remaining_mines == columns - 1:
            #print('er+sp')
            if columns == 2:
                return None
            for c in range(2, columns):
                board[empty_rows - 1][c] = '*'
            board[empty_rows - 2][columns - 1] = '*'
            return board
        else:
            for c in range(columns - remaining_mines, columns):
                board[empty_rows - 1][c] = '*'
            return board

    empty_cols = columns
    while remaining_mines >= empty_rows and empty_cols > 2:
        remaining_mines -= empty_rows;
        empty_cols -= 1
        for r in range(empty_rows):
            board[r][empty_cols] = '*'

    if empty_rows == 3:
        #print('er3')
        if remaining_mines > 2:
            return None
        if remaining_mines == empty_cols - 1 and empty_cols > 1:
            return None
        for c in range((empty_cols - remaining_mines), empty_cols):
            board[2][c] = '*'
        return board

    if empty_rows in (1, 2):
        #print('er12')
        if remaining_mines == 0:
            return board
        else:
            return None

    assert False

def flatten_board(board):
    return sum(board, [])

def test_solution(board):
    board = list(map(list, board))
    rows = len(board)
    cols = len(board[0])

    def in_board(r, c):
        return 0 <= r < rows and 0 <= c < cols
    def near_mine(r, c):
        return any(in_board(dr + r, dc + c) and board[dr + r][dc + c] == '*' for dr in [-1, 0, 1] for dc in [-1, 0, 1])

    for r in range(rows):
        for c in range(cols):
            if board[r][c] == 'c':
                start_pos = (r, c)
                board[r][c] = '.'
            if board[r][c] == '.' and near_mine(r, c):
                board[r][c] = 'x'

    visited = set()
    to_visit = set([start_pos])
    while to_visit:
        r, c = to_visit.pop()
        if (r, c) in visited:
            continue
        visited.add((r, c))
        if board[r][c] == '.':
            for dr in [-1, 0, 1]:
                for dc in [-1, 0, 1]:
                    if not in_board(r + dr, c + dc): continue
                    to_visit.add((r + dr, c + dc))
        board[r][c] = 'v'
    flat_board = flatten_board(board)
    #print(board)
    return not ('.' in flat_board or 'x' in flat_board)

def format_board(board):
    return '\n'.join(''.join(row) for row in board)

def read_one():
    return list(map(int, input().split()))

def main():
    ncases = int(input())
    for i in range(1, ncases + 1):
        rows, columns, mines = read_one()
        board = solve(rows, columns, mines)
        print('Case #{}:'.format(i))
        if not board:
            print('Impossible')
        else:
            assert len(board) == rows
            assert all(len(column) == columns for column in board)
            if not flatten_board(board).count('*') == mines:
                raise Exception('Wrong number of mines (expected {}): {}'.format(mines, format_board(board)))
            if not test_solution(board):
                raise Exception('Wrong solution: {}'.format(format_board(board)))
            print(format_board(board))


from math import factorial

def num_combinations(n, r):
    return factorial(n + r - 1) // factorial(r) // factorial(n - 1)

def bruteforce(rows, columns, mines):
    from itertools import combinations, product
    board_positions = list(product(range(rows), range(columns)))
    board_positions.remove((0, 0))
    for mine_positions in combinations(board_positions, mines):
        board = [['.'] * columns for i in range(rows)]
        board[0][0] = 'c'
        for pos in mine_positions:
            board[pos[0]][pos[1]] = '*'
        if test_solution(board):
            return board
    return None

def verify_impossibles():
    from re import search
    base = 'C-small-attempt2'
    inlines = open(base + '.in', 'r').readlines()
    outlines = open(base + '.out', 'r').readlines()
    while 'Impossible\n' in outlines:
        i = outlines.index('Impossible\n')
        case = int(search('\d+', outlines[i - 1]).group(0))
        rows, columns, mines = map(int, inlines[case].split())
        print(case, rows, columns, mines)
        ncombs = num_combinations(rows * columns - 1, mines)
        if ncombs < 2 ** 40:
            solution = bruteforce(rows, columns, mines)
            if solution:
                print("Found solution")
                print(format_board(solution))
                raise Exception()
        else:
            print("Skipped case", case, ncombs)
        outlines[i] = 'checked'


main()
#verify_impossibles()
