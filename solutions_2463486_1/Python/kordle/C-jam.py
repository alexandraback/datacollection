from helpers import *
import os.path
from fractions import Fraction
import re
import sys
import math
sys.setrecursionlimit(10000)
from Queue import Queue


prefix = 'C'


def pals(numdigs):
    # not sure why this case is needed
    if numdigs == 1:
        for i in [1,2,3,4,5,6,7,8,9]: yield i
        return
    odd = (numdigs % 2 == 1)
    size = numdigs/2
    for i in xrange(10**(size-1),10**size):
        f = todigits(i)
        rev = list(reversed(f))
        if odd:
            for d in xrange(10):
                yield fromdigits(f + [d] + rev )
        else:
            yield fromdigits(f + rev )

def enum_pals(low,high):
    lowdigs = todigits(low)
    highdigs = todigits(high)
    for numdigs in xrange(len(lowdigs), len(highdigs)+1):
        for pal in pals(numdigs):
            if pal > high: break
            if pal >= low: yield pal
        

def ispal(seq):
    for i in xrange(len(seq)/2):
        if seq[i] != seq[-i-1]: return False
    return True


def solve(global_details, prob):
    _ = global_details
    A,B = prob

    tot = 0
    for p in enum_pals(int(math.sqrt(A)), int(math.sqrt(B))+2):
        p = p*p
        if p >= A and p <= B and ispal(todigits(p)): tot += 1
    return tot




def read_single_problem(f):
    ''' nextline(f)
        intline(f)
        firstint(f)
    '''
    A,B = intline(f)
    return A,B

    
        


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
largesuffix = '-large-1'
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
