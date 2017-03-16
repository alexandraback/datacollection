from helpers import *
import os.path
from fractions import Fraction
import re
import sys
import math
sys.setrecursionlimit(10000)
from Queue import Queue


prefix = 'B'




def solve(global_details, prob):
    _ = global_details
    N, M, grid = prob
    explained = [[False for c in r] for r in grid]

    def locs(h):
        for i in xrange(N):
            for j in xrange(M):
                if grid[i][j] == h: yield i,j
    def rowsane(r,h):
        for j in xrange(M):
            if grid[r][j] > h and not explained[r][j]: return False
        return True
    def colsane(c,h):
        for j in xrange(N):
            if grid[j][c] > h and not explained[j][c]: return False
        return True

    heights = sorted(list(set([h for r in grid for h in r])))

    for h in heights:
        for i,j in locs(h):
            if rowsane(i,h) or colsane(j,h):
                explained[i][j] = True
            else:
                return 'NO'
    return 'YES'
##    
##    print heights
##
##    rowmax = [max([grid[r][c] for c in xrange(M)]) for r in xrange(N)]
##    colmax = [max([grid[r][c] for r in xrange(N)]) for c in xrange(M)]
##
##    for r in xrange(N):
##        for c in xrange(M):
##            h = grid[r][c]
##            if h < rowmax[r] and h < colmax[c]:
##                return 'NO'
##
##    return 'YES'

        
        





def read_single_problem(f):
    ''' nextline(f)
        intline(f)
        firstint(f)
    '''
    N,M = intline(f)
    grid = [intline(f) for i in xrange(N)]
    return N, M, grid

    
        


def read_global_details(f):
    numcases = firstint(f)
    return None, numcases


def solve_many(filename):
    print 'Solving file', filename
    f = open(filename + inextension, 'r')
    of = open(filename + outextension, 'w')
    global_details, numcases  = read_global_details(f)
    for cnum in xrange(1, numcases+1):
        p = read_single_problem(f)
        line = 'Case #{}: {}'.format(cnum, solve(global_details, p))
        print line
        of.write(line + '\n')
        
    f.close()
    of.close()
    return True



inextension, outextension = '.in', '.out'
largesuffix = '-large'
smallsuffix = '-small-attempt0'
tinysuffix = '-tiny'

def fexists(fname):
    return os.path.isfile(fname + inextension)

if __name__ == '__main__':
    tinyinstancefile = prefix + tinysuffix
    smallinstancefile = prefix + smallsuffix
    largeinstancefile = prefix + largesuffix
    if fexists(largeinstancefile): solve_many(largeinstancefile)
    elif fexists(smallinstancefile): solve_many(smallinstancefile)
    elif fexists(tinyinstancefile): solve_many(tinyinstancefile)
    else: print 'NO INPUT FILES DETECTED'
