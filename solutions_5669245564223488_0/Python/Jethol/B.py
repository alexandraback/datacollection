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
    [N, cars] = casedata
    result = 0
    for car in itertools.permutations(cars):
        letters = set()
        ca = "".join(car)
        l = ''
        inc = 1
        for r in ca:
            if r != l:
                if r in letters:
                    inc = 0
                    break
                l = r
                letters.add(r)
        result = result + inc % 1000000007

    return str(result)

def parse():
    """ Returns a list of N lists containing imput data for each case """
    t = int(sys.stdin.readline())
    cases = list()
    for case in range(t):
        N = int(sys.stdin.readline())
        cars = sys.stdin.readline().rstrip('\n').split()
        casedata = [N, cars]
        cases.append(casedata)
    return cases

if __name__ == '__main__':
    cases = parse()
    p = multiprocessing.Pool(multiprocessing.cpu_count())
    results = p.map(solve, cases)
    for case, result in enumerate(results):
        print('Case #%d: %s' % (case + 1, result))
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
