# Code by David Kordalewski
# davekordalewski@gmail.com


# too many imports
from helpers import *
import os.path
from fractions import Fraction
import re
import sys
import math
sys.setrecursionlimit(10000) # in case we want to memoize something deep

prefix = 'A'

largesuffix = '-large'
smallsuffix = '-small-attempt0'
tinysuffix = '-tiny'


def solve(global_details, prob):
    _ = global_details
    r, t = prob

    a = int((math.sqrt(1 - 4*r + 4*r**2 + 8*t) - 2*r +1) / 4.0)

    for k in xrange(a+100, a-10000,-1):
        tot = k * (2 * (k + r) - 1)
        if tot <= t:
            return k

    
        
    return a



def read_single_problem(f):
    ''' nextline(f)
        intline(f)
        firstint(f)
    '''
    r, t = intline(f)
        
    return r, t




##################################################
# Boilerplate Below
##################################################


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


def fexists(fname):
    return os.path.isfile(fname + inextension)

if __name__ == '__main__':
    files = [largesuffix, smallsuffix, tinysuffix, ]
    for f in files:
        fname = prefix + f
        if fexists(fname):
            solve_many(fname)
            break
    print 'NO INPUT FILES DETECTED'
    
