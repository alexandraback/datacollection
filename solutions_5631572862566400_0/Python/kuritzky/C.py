# -*- coding: utf-8 -*-
"""
Problem C. 
uses python 3.4.1

@author: Eric Kuritzky
"""
from collections import *
import itertools as ito
import operator as op
import functools as ft
from sys import argv, stdin, stdout, stderr, setrecursionlimit

#setrecursionlimit(1000000)

errprt = ft.partial(print, file=stderr)

Kidinfo = namedtuple('Kidinfo', ['cycle', 'nearest', 'dist'])
    
def readcase(f):
    n = int(f.readline().strip())
    case = readints(f)
    assert n == len(case)
    return [i-1 for i in case]

def solvecase(case):
    cycledat = getkind(case)
    biggestcycle = max(len(dat.cycle) for dat in cycledat)
    bestlead = [0] * len(case)
    for dat in cycledat:
        if len(dat.cycle)==2:
            bestlead[dat.nearest] = max(bestlead[dat.nearest], dat.dist+1)
    return max(biggestcycle, sum(bestlead))

def getkind(case):
    kind = [None] * len(case) # kind[k] = (cycle, nearest, dist)
    for kid, k in enumerate(kind):
        if k is not None:
            continue
        seen = dict()
        while True:
            if kid in seen:
                cycle = getcycle(kid, seen)
                lead = len(seen)-len(cycle)
                for k, fromstart in seen.items():
                    if fromstart < lead:
                        kind[k] = Kidinfo(cycle, cycle[0], lead-fromstart)
                    else:
                        kind[k] = Kidinfo(cycle, k, 0)
                break
            if kind[kid] is not None:
                cycle, nearest, dist = kind[kid]
                for k, fromstart in seen.items():
                    kind[k] = Kidinfo(cycle, nearest, dist+len(seen)-fromstart)
                break
            seen[kid] = len(seen)
            kid = case[kid]
    return kind

def getcycle(kid, seen):
    cycle = [None] * (len(seen)-seen[kid])
    for k, fromstart in seen.items():
        index = seen[k] - seen[kid]
        if index >= 0:
            cycle[index] = k
    assert None not in cycle
    return tuple(cycle)
	
def readints(f):
    return list(map(int, f.readline().strip().split(' ')))

def readflds(f, types):
    if isinstance(types, tuple):
        return [typ(fld) for fld, typ
                in zip(f.readline().strip().split(),
                       ito.chain(types, ito.repeat(types[-1])))]
    else:
        return [types(fld) for fld in f.readline().strip().split()]

def main():
    with open(argv[1]) as f, open('out', 'w') as out:
        cases = int(f.readline())
        for ncase in range(1, cases+1):
            case = readcase(f)
            soln = solvecase(case)
            if len(argv) > 2:
                print('Case #%d: %s' % (ncase, soln))
            print('Case #%d: %s' % (ncase, soln), file=out)

from datetime import datetime

start = datetime.now()
print(str(start))
main()
stop = datetime.now()
print(str(stop-start))
