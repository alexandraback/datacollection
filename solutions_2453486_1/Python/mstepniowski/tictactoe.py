CHECKS = ([(n, n + 1, n + 2, n + 3) for n in range(0, 15, 4)] # rows
          + [(n, n + 4, n + 8, n + 12) for n in range(4)] # columns
          + [(0, 5, 10, 15), (3, 6, 9, 12)]) # diagonals


def tictactoe(board):
    for check in CHECKS:
        if all(board[i] in ('O', 'T') for i in check):
            return 'O won'
        if all(board[i] in ('X', 'T') for i in check):
            return 'X won'
    if '.' in board:
        return 'Game has not completed'
    else:
        return 'Draw'


def read_numbers(line):
    if line[-1] == '\n':
        line = line[:-1]
    return [int(x) for x in line.split()]


if __name__ == '__main__':
    import sys
    case_count = int(sys.stdin.readline()[:-1])
    for i in range(1, case_count + 1):
        board = ''.join(sys.stdin.readline()[:-1] for x in range(4))
        sys.stdin.readline()
        print "Case #{}: {}".format(i, tictactoe(board))
