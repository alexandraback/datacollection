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


def calcReachable(Ds, V):
    D = len(Ds)
    reachable = set()
    for i in range(2**len(Ds)):
        value = 0
        for j in range(D):
            if i & (1 << j) != 0:
                value += Ds[j]
        if value <= V and value != 0:
            reachable.add(value)
    return reachable

def solve(casedata):
    """ Solve case """
    C, D, V, Ds = casedata
    necessary = (i for i in [1, 2] if i <= V)
    nbadded = 0
    for i in necessary:
        if i not in Ds:
            nbadded += 1
            Ds.append(i)
    reachable = calcReachable(Ds, V)
    while len(reachable) != V:
        smallestmissing = min([i for i in range(1, V+1) if i not in reachable])
        Ds.append(smallestmissing)
        nbadded += 1
        reachable = calcReachable(Ds, V)

    return nbadded

def parse():
    """ Returns a list of N lists containing imput data for each case """
    t = int(sys.stdin.readline())
    cases = list()
    for case in range(t):
        mountain = list()
        caves = {}
        C, D, V = map(int, sys.stdin.readline().rstrip('\n').split())
        Ds = map(int, sys.stdin.readline().rstrip('\n').split())
        casedata = [C, D, V, Ds]
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
