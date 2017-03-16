import itertools

def lines(board):
    for line in board:
        yield map(lambda c: c, line)

def cols(board):
    for i in range(4):
        yield map(lambda line: line[i], board)

def diagonals(board):
    yield [board[0][0], board[1][1], board[2][2], board[3][3]]
    yield [board[0][3], board[1][2], board[2][1], board[3][0]]

def combinations(board):
    return itertools.chain(lines(board), cols(board), diagonals(board))

def result(board):
    d = 0
    for line in combinations(board):
        t = line.count('T')
        x = line.count('X')
        o = line.count('O')
        d += line.count('.')
        if t + x == 4:
            return 'X won'
        elif t + o == 4:
            return 'O won'
    if d == 0:
        return 'Draw'
    return 'Game has not completed'

with open("input.txt") as f:
    file_lines = f.readlines()

    n = int(file_lines[0])
    for i in range(n):
        board = map(lambda line: line.strip(), file_lines[(i*5)+1:(i*5)+5])
        print "Case #%d: %s" % (i + 1, result(board))
