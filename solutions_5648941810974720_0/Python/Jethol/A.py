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
import scipy
import scipy.stats as stats
import argparse
import numpy

nums = ('ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT',
        'NINE', 'TEN')

def strtoarray(s):
    a = numpy.zeros(26)
    for c in s:
        o = ord(c) - ord('A')
        a[o] += 1
    return a

nummat = numpy.zeros((0, 26))
for idx, n in enumerate(nums):
    a = strtoarray(n)
    nummat = numpy.vstack((nummat, a))

nummat = nummat.T


def solve(casedata):
    """ Solve case """
    [s] = casedata
    b = strtoarray(s)

    res = ""
    x = numpy.linalg.lstsq(nummat, b)[0]
    for idx, num in enumerate(x):
        nbnum = int(round(num))
        res += nbnum * str(idx)


    return res

def parse():
    """ Returns a list of N lists containing imput data for each case """
    t = int(sys.stdin.readline())
    cases = list()
    for case in range(t):
        s = sys.stdin.readline().rstrip('\n')
        casedata = [s]
        cases.append(casedata)
    return cases

if __name__ == '__main__':
    aparser = argparse.ArgumentParser()
    aparser.add_argument('-m', '--multiprocessing', action='store_true', default=False, required=False)
    aparser.add_argument('-t', '--test-parser', action='store_true', default=False, required=False)
    args = aparser.parse_args()
    cases = parse()
    if args.test_parser:
        print(cases)
        sys.exit(1)
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
