# -*- coding: utf-8 -*-
"""
Problem A. 
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
    
def readcase(f):
    return f.readline().strip()

def solvecase(case):
    left, right =  [case[0]], []
    for letter in case[1:]:
        if letter >= left[-1]:
            left.append(letter)
        else:
            right.append(letter)
    return ''.join(reversed(left))+''.join(right)
	
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
