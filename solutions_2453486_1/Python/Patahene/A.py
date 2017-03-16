#!/usr/bin/env python

import itertools
import os.path as path
from collections import namedtuple, Counter
import pprint
import numpy as np

XA = np.array(['X']*4)
OA = np.array(['O']*4)
TA = np.array(['T']*4)
DA = np.array([['.']*4]*4)

def read_testcase(f):
    board = []
    for i in xrange(4):
        board.append(map(lambda x: x, f.readline().strip()))
    f.readline()


    return np.array(board)

def solve(bd):
    # row check
    for i in xrange(4):
        if np.count_nonzero((bd[i] == XA) | (bd[i] == TA)) == 4:
            return 'X won'
        elif np.count_nonzero((bd[i] == OA) | (bd[i] == TA)) == 4:
            return 'O won'
    # col check
    for i in xrange(4):
        if np.count_nonzero((bd[:, i].T == XA) | (bd[:, i].T == TA)) == 4:
            return 'X won'
        elif np.count_nonzero((bd[:, i].T == OA) | (bd[:, i].T == TA)) == 4:
            return 'O won'

    # diagonal check
    bsi = (0, 1, 2, 3)
    if np.count_nonzero((bd[bsi, bsi] == XA) | (bd[bsi, bsi] == TA)) == 4:
        return 'X won'
    elif np.count_nonzero((bd[bsi, bsi] == OA) | (bd[bsi, bsi] == TA)) == 4:
        return 'O won'

    if np.count_nonzero((bd[bsi[::-1], bsi] == XA) | (bd[bsi[::-1], bsi] == TA)) == 4:
        return 'X won'
    elif np.count_nonzero((bd[bsi[::-1], bsi] == OA) | (bd[bsi[::-1], bsi] == TA)) == 4:
        return 'O won'

    # drow check
    if np.count_nonzero(bd == DA) > 0:
        return 'Game has not completed'
    else:
        return 'Draw'

if __name__ == '__main__':
    ans = []
    with open('A-large.in') as f:
        T = int(f.readline())
        print T
        for i in xrange(T):
            ans.append(solve(read_testcase(f)))

    with open('ans.txt', 'w') as f:
        for i, a in enumerate(ans, start=1):
            f.write('Case #%d: %s\n'%(i, a))

