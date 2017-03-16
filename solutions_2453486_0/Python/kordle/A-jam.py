from helpers import *
import os.path
from fractions import Fraction
import re
import sys
import math
sys.setrecursionlimit(10000)
from Queue import Queue


prefix = 'A'

def lines(grid):
    yield [grid[j][j] for j in xrange(4)]
    yield [grid[j][-j-1] for j in xrange(4)]
    for i in xrange(4):
        yield [grid[i][j] for j in xrange(4)]
        yield [grid[j][i] for j in xrange(4)]

def won(symbs, grid):
    for line in lines(grid):
        if all(c in symbs for c in line):
            return True
    return False
                


def solve(global_details, prob):
    _ = global_details
    grid = prob


##    print grid
    
    if won('XT', grid): return 'X won'
    if won('OT', grid): return 'O won'

    undone = any(['.' in row for row in grid])
    if undone: return 'Game has not completed'
    return 'Draw'
        
        





def read_single_problem(f):
    ''' nextline(f)
        intline(f)
        firstint(f)
    '''
    rows = [[c for c in nextline(f)] for k in range(4)]
    nextline(f)
    return rows

    
        


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
largesuffix = '-large-attempt0'
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
