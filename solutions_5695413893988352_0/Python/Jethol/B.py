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
    [C, J] = casedata
    mindiff = 1e19
    newc = 0
    newj = 0
    cbase = 0
    idxc = []
    for idx, c in enumerate(reversed(C)):
        if c == '?':
            idxc.append(idx)
        else:
            cbase += (10**(idx)) * int(c)
    jbase = 0
    idxj = []
    for idx, c in enumerate(reversed(J)):
        if c == '?':
            idxj.append(idx)
        else:
            jbase += (10**(idx)) * int(c)

    for pc in range(10**len(idxc)):
        for pj in range(10**len(idxj)):
            ccan = cbase
            jcan = jbase
            b = 1
            for ij in idxj:
                jcan += (pj % (10*b)) / b * 10**ij
                b *= 10
            b = 1
            for ic in idxc:
                ccan += (pc % (10*b)) / b * 10**ic
                b *= 10
            # print C, cbase, idxc, pc, ccan
            # print J, jbase, idxj, pj, jcan
            diff = abs(jcan - ccan)
            # print ccan, jcan, diff
            if diff < mindiff:
                # print "new diff", diff, newc, newj, idxc, idxj, C, J
                mindiff = diff
                newc = ccan
                newj = jcan
            elif diff == mindiff:
                if ccan < newc:
                    mindiff = diff
                    newc = ccan
                    newj = jcan
                elif ccan == newc:
                    if jcan < newj:
                        mindiff = diff
                        newc = ccan
                        newj = jcan
    sc = str(newc).zfill(len(C))
    sj = str(newj).zfill(len(J))
    return "%s %s" % (sc, sj)

def parse():
    """ Returns a list of N lists containing imput data for each case """
    t = int(sys.stdin.readline())
    cases = list()
    for case in range(t):
        C, J = sys.stdin.readline().rstrip('\n').split(' ')
        casedata = [C, J]
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
