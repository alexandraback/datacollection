#!/usr/bin/env python

N = int(raw_input())

def winner(c):
    nX = c.count('X')
    nO = c.count('O')
    if nX == 4:
        return 'X'
    elif nO == 4:
        return 'O'
    elif nX == 3:
        if c.count('T') == 1:
            return 'X'
    elif nO == 3:
        if c.count('T') == 1:
            return 'O'
    else:
        return None

def solve(case, board):
    candidates = []
    for i in range(4):
        candidates.append([(i, 0), (i, 1), (i, 2), (i, 3)])
        candidates.append([(0, i), (1, i), (2, i), (3, i)])
    candidates.append([(0, 0), (1, 1), (2, 2), (3, 3)])
    candidates.append([(0, 3), (1, 2), (2, 1), (3, 0)])

    for c in candidates:
        w = winner(board[c[0][0]][c[0][1]] + \
                   board[c[1][0]][c[1][1]] + \
                   board[c[2][0]][c[2][1]] + \
                   board[c[3][0]][c[3][1]])
        if w is not None:
            print('Case #%d: %s won' % (case, w))
            return

    for row in board:
        if '.' in row:
            print('Case #%d: Game has not completed' % (case))
            return

    print('Case #%d: Draw' % (case))
    return

for i in range(N):
    lines = [None, None, None, None]
    for j in range(4):
        lines[j] = raw_input()
    solve(i + 1, lines)
    raw_input()
