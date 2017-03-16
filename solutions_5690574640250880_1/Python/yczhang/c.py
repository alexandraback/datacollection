import sys


def empty_board(r, c):
    return [ ['*'] * c for i in xrange(r)]

def fill_board(board, r1, c1, r2, c2):
    for i in xrange(r1, r2):
        for j in xrange(c1, c2):
            board[i][j] = '.'

def print_board(board):
    R = len(board)
    C = len(board[0])

    for i in xrange(R):
        for j in xrange(C):
            if i == 0 and j == 0:
                sys.stdout.write('c')
            else:
                sys.stdout.write(board[i][j])
        sys.stdout.write('\n')

def solve():
    R, C, M = map(int, sys.stdin.readline().split())

    board = empty_board(R, C)

    E = R * C - M

    if E == 1:
        fill_board(board, 0, 0, 1, 1)
        return board
    elif R == 1:
        fill_board(board, 0, 0, 1, E)
        return board
    elif C == 1:
        fill_board(board, 0, 0, E, 1)
        return board

    if M == 0:
        fill_board(board, 0, 0, R, C)
        return board

    if M <= (R-2) * (C-2):
        fill_board(board, 0, 0, 2, C)
        fill_board(board, 0, 0, R, 2)

        EE = (R-2) * (C-2) - M

        fill_board(board, 2, 2, R, 2 + EE / (R-2))
        fill_board(board, 2, 2 + EE / (R-2), 2 + EE%(R-2), 2 + EE/(R-2) + 1)

        return board

    for r1 in xrange(2, R+1):
        for r2 in xrange(0, R+1):
            for c2 in xrange(2, C+1):
                for c1 in xrange(c2, C+1):
                    if (r1 + r2 <= R and r1 * c1 + r2 * c2 == E):
                        fill_board(board, 0, 0, r1, c1)
                        fill_board(board, r1, 0, r1+r2, c2)
                        return board

    return None

T = int(sys.stdin.readline())
for t in xrange(T):
    res = solve()

    sys.stdout.write('Case #%d:\n' % (t+1))
    if res is None:
        sys.stdout.write('Impossible\n')
    else:
        print_board(res)

