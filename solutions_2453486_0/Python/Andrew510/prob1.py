#!/usr/bin/python

import sys
infile = sys.stdin
#infile = open('in.txt', 'r')

def winner(L):
    who = L[0]
    if who == 'T':
        who = L[1]
    if who == '.':
        return None

    if all([ x == who or x == 'T' for x in L]):
        return who
    else:
        return None

def lines(board):
    for line in board:
        yield line
    
    for c in range(4):
        col = list([ board[r][c] for r in range(4) ])
        yield col

    yield ( board[0][0], board[1][1], board[2][2], board[3][3] )
    yield ( board[0][3], board[1][2], board[2][1], board[3][0] )


T = int(infile.readline())
for t in range(T):
    board = [ infile.readline().strip() for _ in range(4) ]
    infile.readline()
    
    result = None
    for l in lines(board):
        w = winner(l)
        if w is not None:
            result = '%s won' % w
            break
    
    if result is None:
        result = 'Draw'
        for l in board:
            try:
                i = l.index('.')
                result = 'Game has not completed'
                break
            except ValueError:
                pass
    
    print 'Case #%d: %s' % (t+1, result)
        
