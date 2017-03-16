from helpers import *
import os.path
from fractions import Fraction
import re
import sys
sys.setrecursionlimit(10000)


prefix = 'A'


def solve(global_details, prob):
    _ = global_details
    N, L, P = prob

    order = []

    exps = {i: Fraction(P[i]) for i in xrange(N)}
    while len(exps) > 0:
        loc, best = 9999, -1
        for i in exps.keys():
            if exps[i] > best: loc, best = i, exps[i]
            elif exps == best and i < loc: loc = i
        order.append(loc)
        del exps[loc]

    
    return order



def read_single_problem(f):
    ''' nextline(f)
        intline(f)
        firstint(f)
    '''
    N = firstint(f)
    L = intline(f)
    P = intline(f)
        
    return N, L, P



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
largesuffix = '-large-practice'
smallsuffix = '-small-practice'
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
