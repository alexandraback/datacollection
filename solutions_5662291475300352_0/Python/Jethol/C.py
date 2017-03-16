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
    groups = casedata
    nbhikers = sum([d[1] for d in groups])
    if nbhikers <= 1:
        return 0
    else:
        # 2 hikers
        hikers = []
        for d, h, m in groups:
            for i in range(h):
                hikers.append([m+i, d])
        hikers.sort()
        #  time for slowest to cross 0 once
        ts = float(360 - hikers[1][1]) * hikers[1][0] / 360
        tf = float(360 + 360 - hikers[0][1]) * hikers[0][0] / 360
        if ts > tf:
            return 1
        if ts < tf:
            return 0
        if ts == tf:
            return 2


def parse():
    """ Returns a list of N lists containing imput data for each case """
    t = int(sys.stdin.readline())
    cases = list()
    for case in range(t):
        N = int(sys.stdin.readline().rstrip('\n'))
        groups = []
        for n in range(N):
            D, H, M = map(int, sys.stdin.readline().rstrip('\n').split())
            groups.append((D, H, M))
        casedata = groups
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
