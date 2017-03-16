# coding: utf-8 
from __future__ import division
import itertools
import math
#import numpy

def read_word(f):
	return next(f).strip()

def read_int(f, b=10):
	return int(read_word(f), b)

def read_letters(f):
	return list(read_word(f))

def read_digits(f, b=10):
	return [int(x, b) for x in read_letters(f)]

def read_words(f, d=' '):
	return read_word(f).split(d)

def read_ints(f, b=10, d=' '):
    return [int(x, b) for x in read_words(f, d)]
 
def read_arr(f, R, reader=read_ints, *args, **kwargs):
    res = []
    for i in range(R):
        res.append(reader(f, *args, **kwargs))
    return res
 
def solve(solver, fn, out_fn=None):
    in_fn = fn + '.in'
    if out_fn is None:
        out_fn = fn + '.out'
    with open(in_fn, 'r') as fi:
        with open(out_fn, 'w') as fo:
            T = read_int(fi)
            for i in range(T):
                case = read_case(fi)
                res = solver(case)
                write_case(fo, i+1, res)
 
################################################################################
 
def read_case(f):
    N = read_int(f)
    ##print N
    Cs = []
    for i in range(N):
        D = read_ints(f)
        #print D
        Cs.append(D)
    return (N, Cs)
 
def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')
 
################################################################################
 
INF = float('inf')
 
import heapq
 
def solve_small(case):
    (N, Cs) = case
    Ds = [None]*N
    Refs = []
    for i in range(N):
        Refs.append(list())
        Ds[i] = list(Cs[i])
        for j in range(Ds[i][0]):
            ref = Ds[i][1+j]
            Refs[i].append(ref)
    #print Refs

    for i in range(N):
        curList = []
        curList.extend(Refs[i])
        
        l = 0
        while (l < len(curList)):
            next = curList[l] - 1
            for k in Refs[next]:
                if k in set(curList):
                    return 'Yes'
                else:
                    curList.append(k)
            l += 1
        #print str(i) + ' ' + str(curList)

        #for j in range(len(Refs[i])):
        #    next = Refs[i][j]-1
        #    print Refs[next]
        #    for k in Refs[next]:
        #        if k not in curSet:
        #            curSet.add(k)
        #    print curSet




    return 'No'
 
solve_large = solve_small
 






solve(solve_large, "DiamondInheritance")


 
DEBUG = 'i'
##from run import *