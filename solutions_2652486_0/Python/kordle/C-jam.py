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

prefix = 'C'

largesuffix = '-large'
smallsuffix = '-small-1-attempt2'
tinysuffix = '-tiny'

def products(lis):    
    if len(lis) == 1:
        yield lis[0]
        yield 1
    else:
        for p in products(lis[1:]):
            yield p
            yield lis[0] * p

def getdistro(lis):
    ret = defaultdict(lambda: -9999999.0)
    for prod in products(lis):
        ret[prod] += 1
    tot = sum(ret.values())
    for k in ret.keys():
        ret[k] = math.log(ret[k] / float(tot))
    return ret

def solve(global_details, prob):
    R, N, M, K = global_details
    probs = prob


    dist = {}
    for a in xrange(2,M+1):
        for b in xrange(a,M+1):
            for c in xrange(b,M+1):
                dist[(a,b,c)] = getdistro([a,b,c])
##                print dist[(a,b,c)]

    ret = []


    for prob in probs:
        maxl = -99999999990
        pick = [2] * N
        print prob
        for dis in dist.keys():
            distro = dist[dis]
            sucks = False
            for k in prob:
                if k not in distro.keys():
                    sucks = True
            if sucks: continue
            t = sum(distro[k] for k in prob)
            
            if t > maxl:
                maxl, pick = t, dis
        ret.append(''.join([str(p) for p in pick]))
##        print maxl, pick, dist[pick]
    return '\n' + '\n'.join(ret)

##    for d in dist.keys():
##        print d, dist[d]
        
        

##    for prob in probs:
##        print prob

        
    return 



def read_single_problem(f):
    ''' nextline(f)
        intline(f)
        firstint(f)
    '''
    prob = f.read().strip().split('\n')
    probs = [[int(i) for i in k.split(' ')] for k in prob]
    
    
    
        
    return probs




##################################################
# Boilerplate Below
##################################################


def read_global_details(f):
    numcases = firstint(f)
    R, N, M, K = intline(f)
    return (R, N, M, K), numcases


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
    
