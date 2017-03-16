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
    data = read_ints(f)
    N = data.pop(0)
    Cs = data
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
    X=0
    notSafe = 0
    for i in range(N):
        X += Cs[i]
    #print X
    Ms = [None]*N
    #Ms = ''
    totalS = 2*X
    totalP = N
    maxJ = totalS/totalP + 1
    while(maxJ > totalS/totalP):
        maxJ = 0
        minS = totalS/totalP
        #print 'minS' + str(minS) 
        for i in range(N):
            if(Ms[i] == 0):
                continue

            if(Cs[i] > maxJ):
                maxJ = Cs[i]

            if(Cs[i] < minS):
                Ms[i] = (minS-Cs[i])/X * 100
            else:
                totalP -= 1
                totalS -= Cs[i]
                Ms[i] = 0

    #print Ms




    result = ''

    for i in range(N):
        result += ' ' + str(Ms[i])
    return result
 
solve_large = solve_small
 
#def solve_large(case):








solve(solve_small, "SafetyInNumbers")


 
##DEBUG = 'i'