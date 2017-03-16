#!/usr/bin/python2
import sys
import multiprocessing
import logging
import os
import itertools
import math
import gmpy2
import copy
import collections
import string
import scipy.stats as stats

def solve(casedata):
    """ Solve case """
    [N, M, K] = casedata
    if M>N:
        M,N=N,M
    MN = M*N
    if M < 3:
        return K
    if K < 5:
        return K
    if K > MN-5:
        return 2*(M+N)-8 + (K-(MN-4))
    #oblong
    if K > M*M-4:
        b = 2*M-4
        r = b
        w = (K-r)/M
        r += 2*w
        add = K-b-w*M
        if add == 1:
            return r+1
        else:
            return r+2
    #carre || L=l+1
    sql = int(math.ceil(math.sqrt(K+3)))
    #rect?
    if K <= sql*(sql-1)-3:
        #rect
        r = 2*(sql-2+sql-3)
        if K==sql*(sql-1)-3:
            r+=1
        return r
    else:
        #square
        r = 4*(sql-2)
        if K==sql*sql-3:
            r+=1
        return r
    return str(result)

def parse():
    """ Returns a list of N lists containing imput data for each case """
    t = int(sys.stdin.readline())
    cases = list()
    for case in range(t):
        N, M, K = map(int, sys.stdin.readline().rstrip('\n').split(' '))
        casedata = [N, M, K]
        cases.append(casedata)
    return cases

if __name__ == '__main__':
    cases = parse()
    p = multiprocessing.Pool(multiprocessing.cpu_count())
    results = p.map(solve, cases)
    for case, result in enumerate(results):
        print('Case #%d: %d' % (case + 1, result))
        sys.stdout.flush()

    #for case, data in enumerate(cases):
    #   result = solve(data)
    #   print('Case #%d: %s' % (case + 1, result))
    #   sys.stdout.flush()

    #p = multiprocessing.Pool(multiprocessing.cpu_count())
    #resultobjs = [p.apply_async(solve, [case]) for case in cases]
    #for case, resultobj in enumerate(resultobjs):
    #    print('Case #%d: %s' % (case + 1, resultobj.get()))
    #    sys.stdout.flush()
