# -*- coding: utf-8 -*-
"""
Problem B. 
uses python 3.3

@author: Eric Kuritzky
"""
from collections import *
import itertools as itool
import operator as op
import functools as ft
from sys import argv, stdin, stdout, stderr
    
def errprt(*args, **kw):
    print(*args, file=stderr, **kw) 
    
def readcase(f):
    return readints(f)

def solvecase(a, b, k):
    cnt = brute(a, b, k)
    return str(cnt)

def brute(a, b, k):
    return sum(aa&bb<k for aa in range(a) for bb in range(b))

def readints(f):
    return list(map(int, f.readline().strip().split(' ')))

def main():
    with open('B-small-attempt0.in') as f, open('out', 'w') as out:
        cases = int(f.readline())
        for ncase in range(1, cases+1):
            case = readcase(f)
            soln = solvecase(*case)
            print('Case #%d: %s' % (ncase, soln))
            print('Case #%d: %s' % (ncase, soln), file=out)

from datetime import datetime

start = datetime.now()
print(str(start))
main()
stop = datetime.now()
print(str(stop))
print(str(stop-start))
