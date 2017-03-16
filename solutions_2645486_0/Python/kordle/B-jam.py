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

prefix = 'B'

largesuffix = '-large'
smallsuffix = '-small-attempt3'
tinysuffix = '-tiny'


def solve(global_details, prob):
    _ = global_details
    E, R, N, V = prob

    maxs = [E] * N
    mins = [0] * N
    tot = 0

    order = reversed(sorted([(v,i) for i, v in enumerate(V)]))

    for v, i in order:
        use = maxs[i] - mins[i]
        tot += use * v
        for dist in xrange(1, N):
            if i+dist >= N: break
            maxs[i+dist] = min(maxs[i+dist], mins[i] + R*dist)
        for dist in xrange(1, N):
            if i-dist < 0: break
            mins[i-dist] = max(mins[i-dist], maxs[i] - R*dist)

    return tot

##    profile = [E] * N
##    mustremain = [0] * N
##    fixed = [False] * N
##
##    tot = 0
##    
##    order = reversed(sorted([(v,i) for i, v in enumerate(V)]))
##    
##    for v,i in order:
##        used = profile[i] - mustremain[i]
##        gain = (used) * v
##        for j in xrange(i,N):
##            if fixed[j] : break
##            newval = min((j-i) * R, E)
##            profile[j] = newval
##            if newval == E: break
##        for j in xrange(i,-1,-1):
##            newval = max(mustremain[j], used - (i-j) * R)
##            mustremain[j] = newval
##            
##
##
##        fixed[i] = True
##
##        
##        tot += gain

    
        
    return tot



def read_single_problem(f):
    ''' nextline(f)
        intline(f)
        firstint(f)
    '''
    E, R, N = intline(f)
    V = intline(f)
        
    return E, R, N, V




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
    
