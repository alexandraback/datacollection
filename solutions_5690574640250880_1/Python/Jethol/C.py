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

def transposestr(grid):
    C = len(grid[0])
    R = len(grid)
    return [''.join([grid[i][j] for i in range(R)]) for j in range(C)]

def draw1(r, c, m):
    return (('c' + (c-m-1) * '.' + m * '*'), )

def draw2(r, c, m):
    f = r * c - m
    if f == 1:
        return (('c' + (c-1) * '*'), c * '*')
    l = f // 2
    return (('c' + (l-1) * '.' + (c-l) * '*'), l * '.' + (c-l) * '*')

def drawN(r, c, m):
    f = r * c - m
    if f == 1:
        return ('c' + (c-1) * '*', ) + (c *  '*', ) * (r - 1)
    if f == 4:
        return draw2(2, c, (2 * c - 4)) + (c *  '*', ) * (r - 2)
    if f == 6:
        return draw2(2, c, (2 * c - 6)) + (c *  '*', ) * (r - 2)
    if f == 8:
        return draw2(2, c, (2 * c - 6)) + ('..' + (c - 2) * '*',) + (c *  '*', ) * (r - 3)
    if m <= (c - 2):
        return draw1(1, c, 0) + (r - 2) * ('.' * c, ) + ((c-m) * '.' + m * '*',)
    fullLines = (f - 4) // c
    result = ()
    if fullLines in (0, 1):
        m = (f - 2) // 2
        result += ('c' + (m - 1) * '.' + (c - m) * '*', )
        result += (m * '.' + (c - m) * '*', ) 
        result += ((f - 2 * m) * '.' + (c - (f-2*m)) * '*', )
        result += ('*' * c,) * (r - 3)
    else:
        result = ('.' * c, ) * fullLines
        r -= fullLines
        f -= fullLines * c
        m = f // 2
        d = f % 2
        result += ('c' + (m + d - 1) * '.' + (c - m - d) * '*', )
        result += (m * '.' + (c - m) * '*', ) 
        result += ('*' * c,) * (r - 2)
    return result


def solve(casedata):
    """ Solve case """
    R, C, M = casedata
    transpose = False
    F = R*C-M
    if R > C:
        transpose = True
        R, C = C, R
    if R == 1:
        result = draw1(R, C, M)
    elif R == 2:
        if (F != 1 and M % 2 == 1) or F == 2:
            return 'Impossible'
        else:
            result = draw2(R, C, M)
    else:
        if F in (2, 3, 5, 7):
            return 'Impossible'
        else:
            result = drawN(R, C, M)
    #
    if transpose:
        return '\n'.join(transposestr(result))
    return '\n'.join(result)

def parse():
    """ Returns a list of N lists containing imput data for each case """
    t = int(sys.stdin.readline())
    cases = list()
    for case in range(t):
        mountain = list()
        caves = {}
        R, C, M = map(int, sys.stdin.readline().rstrip('\n').split())
        casedata = [R, C, M]
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
    #    #sys.stdout.flush()

    p = multiprocessing.Pool(multiprocessing.cpu_count())
    resultobjs = [p.apply_async(solve, [case]) for case in cases]
    for case, resultobj in enumerate(resultobjs):
        print('Case #%d: \n%s' % (case + 1, resultobj.get()))
        sys.stdout.flush()
