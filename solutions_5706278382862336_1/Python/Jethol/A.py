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

def primes(n):
    primfac = []
    d = 2
    while d*d <= n:
        while (n % d) == 0:
            primfac.append(d)  # supposing you want multiple factors repeated
            n /= d
        d += 1
    if n > 1:
       primfac.append(n)
    return primfac

def solve(casedata):
    """ Solve case """
    [P,Q] = casedata
    prq = primes(Q)
    prp = primes(P)
    common = collections.Counter(prq) & collections.Counter(prp)
    psrp = list((collections.Counter(prp) - common).elements())
    psrq = list((collections.Counter(prq) - common).elements())
    if set(psrq) != set([2]):
        return "impossible"
    pq = float(P)/Q
    for g in range(40):
        if pq >= 1./(2**g):
            return str(g)

def parse():
    """ Returns a list of N lists containing imput data for each case """
    t = int(sys.stdin.readline())
    cases = list()
    for case in range(t):
        P, Q = map(int, sys.stdin.readline().rstrip('\n').split('/'))
        casedata = [P, Q]
        cases.append(casedata)
    return cases

if __name__ == '__main__':
    cases = parse()
    #p = multiprocessing.Pool(multiprocessing.cpu_count())
    #results = p.map(solve, cases)
    #for case, result in enumerate(results):
    #    print('Case #%d: %s' % (case + 1, result))
    #    sys.stdout.flush()

    for case, data in enumerate(cases):
        result = solve(data)
        print('Case #%d: %s' % (case + 1, result))
        sys.stdout.flush()

    #p = multiprocessing.Pool(multiprocessing.cpu_count())
    #resultobjs = [p.apply_async(solve, [case]) for case in cases]
    #for case, resultobj in enumerate(resultobjs):
    #    print('Case #%d: %s' % (case + 1, resultobj.get()))
    #    sys.stdout.flush()
