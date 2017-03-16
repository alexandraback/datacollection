# Qualification Round 2014
# Problem C. Minesweeper Master
# MichelJ

import sys
import logging
import StringIO
from itertools import *

def echo(fn):
    def wrapped(*v, **k):
        name = fn.__name__
        logging.info( "Called %s(%s)" % (name, ", ".join(map(repr, chain(v, k.values())))) )
        res = fn(*v, **k)
        logging.info( "       %s(%s) returned %s" % (name, ", ".join(map(repr, chain(v, k.values()))),res) )
        return res
    return wrapped

def goodboard(b,r,c):
    num_zeros = sum(sum(1 for x in row if x==0) for row in b)
    for i in xrange(r):
        for j in xrange(c):
            bij = b[i][j]
            if bij>5:
                return False
            if bij>=0:
                if i>0:
                    if j>0 and b[i-1][j-1]==0:
                        continue
                    if b[i-1][j]==0:
                        continue
                    if j<c-1 and b[i-1][j+1]==0:
                        continue
                if j>0 and b[i][j-1]==0:
                    continue
                if j<c-1 and b[i][j+1]==0:
                    continue
                if i<r-1:
                    if j>0 and b[i+1][j-1]==0:
                        continue
                    if b[i+1][j]==0:
                        continue
                    if j<c-1 and b[i+1][j+1]==0:
                        continue
                if bij>0 or num_zeros>1:
                    return False
    return True

def fillboard(b,r,c):
    for i in xrange(r):
        for j in xrange(c):
            if b[i][j] == -1:
                if i>0:
                    if j>0 and b[i-1][j-1]>=0:
                        b[i-1][j-1]+=1
                    if b[i-1][j]>=0:
                        b[i-1][j]+=1
                    if j<c-1 and b[i-1][j+1]>=0:
                        b[i-1][j+1]+=1
                if j>0 and b[i][j-1]>=0:
                    b[i][j-1]+=1
                if j<c-1 and b[i][j+1]>=0:
                    b[i][j+1]+=1
                if i<r-1:
                    if j>0 and b[i+1][j-1]>=0:
                        b[i+1][j-1]+=1
                    if b[i+1][j]>=0:
                        b[i+1][j]+=1
                    if j<c-1 and b[i+1][j+1]>=0:
                        b[i+1][j+1]+=1

def board_rep(b,r,c):
    rep = ''
    fired = False
    for i in xrange(r):
        rep += '\n'
        for j in xrange(c):
            bij = b[i][j]
            if bij<0:
                rep += '*'
            elif bij==0:
                if fired:
                    rep += '.'
                else:
                    rep += 'c'
                    fired = True
            else:
                rep += '.'
    return rep

def solve(r,c,m):
    if m==r*c-1: # special case with one free cell: it is not 0 but just click on this cell
        b = [[-1 for j in xrange(c)] for i in xrange(r)]
        b[0][0] = 0
        return board_rep(b,r,c)
    squares = product(range(r),range(c))
    for comb in combinations(squares,m):
        b = [[0 for j in xrange(c)] for i in xrange(r)]
        for i,j in comb:
            b[i][j] = -1
        fillboard(b,r,c)
        if goodboard(b,r,c):
            return board_rep(b,r,c)
    return "\nImpossible"
    
def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        (r,c,m) = map(int,raw_input().split(' '))
        print 'Case #%d:%s' % (tc, solve(r,c,m))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""6
5 5 23
3 1 1
2 2 1
4 7 3
10 10 82
3 4 11
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.ERROR)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
