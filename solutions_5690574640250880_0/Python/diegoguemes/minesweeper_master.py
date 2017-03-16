import sys

positions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]

def board_to_str(board):
    return '\n'.join([''.join(row) for row in board])


def mines_of(board, row, column):
    mines = 0
    for y, x in positions:
        if row + y >= 0 and row + y < len(board) and column + x >= 0 and column + x < len(board[row + y]) and board[row + y][column + x] == '*':
            mines += 1
    return mines

def mark_zeros(board, row, column):
    if board[row][column] in ['*', 'x', '0']:
        return
    mines = mines_of(board, row, column)
    board[row][column] = 'x'
    if mines == 0:
        board[row][column] = '0'
        for y, x in positions:
            if row + y >= 0 and row + y < len(board) and column + x >= 0 and column + x < len(board[row + y]):
                mark_zeros(board, row + y, column + x)


def can_create_region_from(board, row, column):
    if board[row][column] != '.':
        return False

    mark_zeros(board, row, column)
    has_zero = False
    non_zeros = 0
    for row in board:
        for cell in row:
            if cell == '.':
                return False
            elif cell == 'x':
                non_zeros += 1
            elif cell == '0':
                has_zero = True
    return has_zero or non_zeros == 1


def first_region(board):
    for i in range(len(board)):
        for j in range(len(board[i])):
            copy = [x[:] for x in board]
            if can_create_region_from(copy, i, j):
                board[i][j] = 'c'
                return board
    return None

def is_factible(board, row, column):
    positions = [(-1, 0), (0, -1), (0, 1), (1, 0)]
    mine_count = 0
    neighbors_count = 0
    for y, x in positions:
        if row + y >= 0 and row + y < len(board) and column + x >= 0 and column + x < len(board[row + y]):
            neighbors_count += 1
            if board[row + y][column + x] == '*':
                mine_count += 1
    non_mines_count = 0
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] != '*':
                non_mines_count += 1
    return not (mine_count == neighbors_count and non_mines_count > 1)


def minesweeper_backtracking_mines(board, i, j, mines):
    if mines == 0:
        #print(board_to_str(board))
        #print("back ^ \n\n")
        return first_region(board)
    if i == len(board) or  j == len(board[i]):
        return
    remaining = len(board[i]) - j + (len(board) - i + 1) * len(board[i])
    if mines > remaining:
        return False
    for candidate in ['*', '.']:
        previous = board[i][j]
        board[i][j] = candidate
        new_mines = mines - 1 if candidate == '*' else mines
        new_j = j + 1
        new_i = i
        if new_j == len(board[i]):
            new_j = 0
            new_i = i + 1
        result = minesweeper_backtracking_mines(board, new_i, new_j, new_mines)
        if result:
            return result
        board[i][j] = previous
    return None

def minesweeper_backtracking_free_cells(board, i, j, free_cells):
    #print(board_to_str(board))
    #print("back ^ \n\n")
    if free_cells == 0:
        return first_region(board)
    if i == len(board) or  j == len(board[i]):
        return
    for candidate in ['.', '*']:
        previous = board[i][j]
        board[i][j] = candidate
        new_free_cells = free_cells - 1 if candidate == '.' else free_cells
        new_j = j + 1
        new_i = i
        if new_j == len(board[i]):
            new_j = 0
            new_i = i + 1
        if True or is_factible(board, new_i, new_j):
            result = minesweeper_backtracking_free_cells(board, new_i, new_j, new_free_cells)
            if result:
                return result
        board[i][j] = previous
    return None


def minesweeper_master(R, C, M):
    if M > R * C - M:
        board = []
        for i in range(R):
            board.append([])
            for j in range(C):
                board[i].append('*')
        converted_board = minesweeper_backtracking_free_cells(board, 0, 0, R * C - M)
        if converted_board:
            return board_to_str(converted_board)
    else:
        board = []
        for i in range(R):
            board.append([])
            for j in range(C):
                board[i].append('.')
        converted_board = minesweeper_backtracking_mines(board, 0, 0, M)
        if converted_board:
            return board_to_str(converted_board)
    return 'Impossible'


T = int(sys.stdin.readline())
for t in range(1, T + 1):
    R, C, M = [int(x) for x in sys.stdin.readline().split()]
    print('Case #{0}:'.format(t))
    print(minesweeper_master(R, C, M))
