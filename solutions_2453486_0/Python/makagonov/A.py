#!/usr/bin/python
import sys
sin, sout = sys.stdin, sys.stdout
rets = ['X won', 'O won', 'Game has not completed', 'Draw']
winX, winO = ['XXXX', 'TXXX'], ['OOOO', 'OOOT']
T = int(sin.readline())
for test in range(T):
    board = [sin.readline().strip() or sin.readline().strip() for i in xrange(0, 4)]
    ret, hasEmpty = '', False
    _all = list(board)
    _all.extend(['' for i in xrange(0, 6)])
    for i in xrange(0, 4):
        _all[-1] += board[i][i]
        _all[-2] += board[i][3 - i]
        for j in xrange(0, 4):
            _all[i + 4] += board[j][i]
            hasEmpty |= board[j][i] == '.'
    for i in _all:
        si = ''.join(sorted(i))
        if si in winX:
            ret = ret or rets[0]
        if si in winO:
            ret = ret or rets[1]
    ret = ret or (rets[2] if hasEmpty else rets[3])
    sout.write('Case #%s: %s\n' % (test + 1, ret))
