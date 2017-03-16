#!/usr/bin/python2
import sys
import multiprocessing
import logging
import os
import itertools
import math
#import gmpy2
import copy
import collections
import string
import scipy.stats as stats


def solve(casedata):
    """ Solve case """
    (naomi, ken, N) = casedata
    warp = 0
    dwarp = 0
    i = 0
    j = 0
    while True:
        if ken[i] > naomi[j]:
            i += 1
            j += 1
        else:
            warp += 1
            i += 1
        if i == N or j == N:
            break
    i = N-1
    j = N-1
    while True:
        if ken[i] > naomi[j]:
            i -= 1
        else:
            i -= 1
            j -= 1
            dwarp += 1
        if i < 0 or j < 0:
            break

    return "%d %d" % (dwarp, warp)

def parse():
    """ Returns a list of N lists containing imput data for each case """
    t = int(sys.stdin.readline())
    cases = list()
    for case in range(t):
        N = int(sys.stdin.readline())
        naomi = sorted(map(float, sys.stdin.readline().split()))
        ken = sorted(map(float, sys.stdin.readline().split()))
        casedata = [naomi, ken, N]
        cases.append(casedata)
    return cases

if __name__ == '__main__':
    cases = parse()
    #p = multiprocessing.Pool(multiprocessing.cpu_count())
    #results = p.map(solve, cases)
    #for case, result in enumerate(results):
    #    print('Case #%d: %s' % (case + 1, result))
    #    sys.stdout.flush()

    #for case, data in enumerate(cases):
    #    result = solve(data)
    #    print('Case #%d: %s' % (case + 1, result))
    #    sys.stdout.flush()

    p = multiprocessing.Pool(multiprocessing.cpu_count())
    resultobjs = [p.apply_async(solve, [case]) for case in cases]
    for case, resultobj in enumerate(resultobjs):
        print('Case #%d: %s' % (case + 1, resultobj.get()))
    #    sys.stdout.flush()
