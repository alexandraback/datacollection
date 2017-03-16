#!/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/bin/python2.7

import sys
from decimal import *
import itertools as it
from math import sqrt
from math import floor
from math import ceil
from math import log
from math import log10
import time
import random
import re
import string

inf = float('inf')

def next_line(filename):
    return f.readline().strip('\n')

def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return it.chain.from_iterable(it.combinations(s, r) for r in range(len(s)+1))

def dec_to_bin(n):
    return bin(n)[2:]

def solve_small(C,denoms,V):
    assert C == 1
    D = len(denoms)
    denoms_added = 0

    if 1 not in denoms:
        denoms.append(1)
        denoms_added += 1

    if V >= 2 and 2 not in denoms:
        denoms.append(2)
        denoms_added += 1

    candidates = set()
    differences = { v: set() for v in range(1,V+1) }

    for v in range(1,V+1):
        can_make = False
        for x in powerset(denoms):
            s = sum(x)
            if s == v:
                can_make = True
                break
            elif s < v and s-v not in denoms:
                differences[v] |= set([s-v])
            
        if not can_make: candidates |= set([v])

    if len(candidates) == 0:
        return denoms_added

    if len(candidates) == 1:
        return denoms_added + 1

    v4 = True
    for v in candidates:
        if 4 not in differences[v]:
            v4 = False
            break
    if v4:
        return denoms_added+1

    v8 = True
    for v in candidates:
        if 8 not in differences[v]:
            v8 = False
            break
    if v8:
        return denoms_added+1

    v16 = True
    for v in candidates:
        if 16 not in differences[v]:
            v16 = False
            break
    if v16:
        return denoms_added+1

    if len(candidates) == 2:
        return denoms_added + 2

    flag = True
    for v in candidates:
        if not (4 in differences[v] or 8 in differences[v]):
            flag = False
            break
    if flag:
        return denoms_added+2
    flag = True
    for v in candidates:
        if not (4 in differences[v] or 16 in differences[v]):
            flag = False
            break
    if flag:
        return denoms_added+2
    flag = True
    for v in candidates:
        if not (16 in differences[v] or 8 in differences[v]):
            flag = False
            break
    if flag:
        return denoms_added+2

    return denoms_added + 3

infile = sys.argv[1]
f = open(infile,'r')

T = int(next_line(f))
for t in range(T):
    C,D,V = map(int,next_line(f).split())
    denoms = map(int,next_line(f).split())
    print 'Case #{}: {}'.format(t+1,solve_small(C,denoms,V))
f.close()
