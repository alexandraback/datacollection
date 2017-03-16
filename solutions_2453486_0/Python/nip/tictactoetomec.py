#!/usr/bin/env python

from sys import stdin
import numpy as np

ntest = input()

def check(row):
    if ((row == 'X') | (row == 'T')).all() == True:
        return 'X won'
    if ((row == 'O') | (row == 'T')).all() == True:
        return 'O won'
    return False

for test in xrange(ntest):
    board = np.zeros((4,4), dtype=np.character)
    for i in xrange(4):
        board[i,:] = list(stdin.readline().strip())
    if test+1 < ntest:
        stdin.readline()
    
    result = False
    for i in xrange(4):
        result = result or check(board[i,:])
        result = result or check(board[:,i])
    result = result or check(board.diagonal())
    result = result or check(board[:,::-1].diagonal())
    
    if not result:
        result = 'Game has not completed' if (board == '.').any() else 'Draw'

    print "Case #{}: {}".format(test+1, result)

