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
import argparse


def solve(casedata):
    """ Solve case """
    K, L, S, kbd, twd = casedata
    # nb keys, twd len, typed len
    # missing letters
    if not all([i in kbd for i in twd]):
        return 0.0
    cnts = collections.Counter(kbd)
    if L == 1:
        # no overlap
        maxnb = S
        expectednb = (float(cnts[twd]) / K) * S
        result = maxnb - expectednb
        return float(result)
    # max overlap?
    overlaps = 0
    for i in range(1, len(twd)):
        if twd.startswith(twd[i:]):
            overlaps = i
            break
    if overlaps == 0:
        maxnb = S / L
    else:
        maxnb = (S - L) / overlaps + 1
    # proba
    probas = [0.0] * L
    lprobas = [float(cnts[l]) / K for l in twd]
    expect = 0.0
    for idx in range(S):
        for pidx in range(len(probas)-1, 0, -1):
            probas[pidx] = lprobas[pidx] * probas[pidx-1]
        probas[0] = lprobas[0]
        expect += probas[-1]

    result = maxnb - expect
    return float(result)

def parse():
    """ Returns a list of N lists containing imput data for each case """
    t = int(sys.stdin.readline())
    cases = list()
    for case in range(t):
        K, L, S = map(int, sys.stdin.readline().rstrip('\n').split())
        kbd = sys.stdin.readline().rstrip('\n')
        twd = sys.stdin.readline().rstrip('\n')
        casedata = [K, L, S, kbd, twd]
        cases.append(casedata)
    return cases

if __name__ == '__main__':
    aparser = argparse.ArgumentParser()
    aparser.add_argument('-m', '--multiprocessing', action='store_true', default=False, required=False)
    args = aparser.parse_args()
    cases = parse()
    if args.multiprocessing:
        p = multiprocessing.Pool(multiprocessing.cpu_count())
        resultobjs = [p.apply_async(solve, [case]) for case in cases]
        for case, resultobj in enumerate(resultobjs):
            print('Case #%d: %s' % (case + 1, resultobj.get()))
            sys.stdout.flush()
    else:
        for case, data in enumerate(cases):
            result = solve(data)
            print('Case #%d: %s' % (case + 1, result))
            #sys.stdout.flush()
        p = multiprocessing.Pool(multiprocessing.cpu_count())

    #results = p.map(solve, cases)
    #for case, result in enumerate(results):
    #    print('Case #%d: %s' % (case + 1, result))
    #    sys.stdout.flush()


    #p = multiprocessing.Pool(multiprocessing.cpu_count())
    #resultobjs = [p.apply_async(solve, [case]) for case in cases]
    #for case, resultobj in enumerate(resultobjs):
    #    print('Case #%d: %s' % (case + 1, resultobj.get()))
    #    sys.stdout.flush()
