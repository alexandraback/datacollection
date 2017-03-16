__author__ = 'karol'

import sys

NOT_FINISHED = 0
X_WON = 1
O_WON = 2
DRAW = 3

FINISHING_STATES = set([X_WON, O_WON])

MESSAGE = {
    NOT_FINISHED: "Game has not completed",
    X_WON: "X won",
    O_WON: "O won",
    DRAW: "Draw"
}


def read_single_case():
    board = [tuple(sys.stdin.readline()[:-1]) for _ in xrange(4)]
    assert sys.stdin.readline() == "\n"
    return board


def check_single_line(line):
    unique = set(line)
    if '.' in unique:
        return NOT_FINISHED
    if unique.issubset(set(['O', 'T'])):
        return O_WON
    if unique.issubset(set(['X', 'T'])):
        return X_WON
    return DRAW


def solve_single_case(board):
    found_not_finished = False

    lines = set(board) | set(zip(*board))
    lines.add(tuple(board[x][x] for x in xrange(4)))
    lines.add(tuple(board[x][3 - x] for x in xrange(4)))

    for line in lines:
        result = check_single_line(line)
        if result in FINISHING_STATES:
            return MESSAGE[result]
        if result == NOT_FINISHED:
            found_not_finished = True

    if found_not_finished:
        return MESSAGE[NOT_FINISHED]
    else:
        return MESSAGE[DRAW]


def main():
    T = int(sys.stdin.readline())

    for case in xrange(1, T+1):
        board = read_single_case()
        solution = solve_single_case(board)
        print "Case #%d: %s" % (case, solution)

main()