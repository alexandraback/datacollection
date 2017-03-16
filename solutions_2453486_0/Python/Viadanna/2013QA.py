#!/usr/bin/python


def analyse_board(board, i):
    for j in xrange(4):
        line = set([board[j][k] for k in xrange(4)])
        line.discard("T")
        if len(line) == 1 and line != set("."):
            return "Case #%d: %s won" % (i, line.pop())
        col = set([board[k][j] for k in xrange(4)])
        col.discard("T")
        if len(col) == 1 and col != set("."):
            return "Case #%d: %s won" % (i, col.pop())
    diag = set([board[j][3 - j] for j in xrange(4)])
    diag.discard("T")
    if len(diag) == 1 and diag != set("."):
        return "Case #%d: %s won" % (i, diag.pop())
    diag = set([board[j][j] for j in xrange(4)])
    diag.discard("T")
    if len(diag) == 1 and diag != set("."):
        return "Case #%d: %s won" % (i, diag.pop())
    for l in board:
        if "." in l:
            return "Case #%d: Game has not completed" % i
    return "Case #%d: Draw" % i


n = int(raw_input())

for i in xrange(1, n + 1):
    board = [raw_input() for j in xrange(4)]
    print analyse_board(board, i)
    try:
        newline = raw_input()
    except:
        pass
