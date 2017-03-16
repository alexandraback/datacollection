
import math
import itertools
import numpy as NP

################################################################################

def read_case(f):
    (A, B, K) = read_ints(f)
    return (A, B, K)

def pats(a):
    s = ['?']*len(a)
    for i in range(len(a)):
        s[i] = '0'
        if a[i] == '1':
            yield s
            s[i] = '1'
    yield s

c = {}
for a in ['0', '1', '?']:
    for b in ['0', '1', '?']:
        for k in ['0', '1', '?']:
            c[a, b, k] = 0
            for ar in range(2) if a == '?' else [int(a)]:
                for br in range(2) if b == '?' else [int(b)]:
                    for kr in range(2) if k == '?' else [int(k)]:
                        if ar & br == kr:
                            c[a, b, k] += 1

def solve_small(case):
    (A, B, K) = case
    A = bin(A-1)[2:]
    B = bin(B-1)[2:]
    K = bin(K-1)[2:]
    n = max(len(A), len(B), len(K))
    A = '0'*(n-len(A)) + A
    B = '0'*(n-len(B)) + B
    K = '0'*(n-len(K)) + K
    s = 0
    for a in pats(A):
        for b in pats(B):
            for k in pats(K):
                m = 1
                for i in range(n):
                    m *= c[a[i], b[i], k[i]]
                s += m
                dbg('a')
                dbg('b')
                dbg('k')
                dbg('m')
    return s

def solve_large(case):
    return solve_small(case)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

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

def read_floats(f, d=' '):
    return [float(x) for x in read_words(f, d)]

def read_arr(f, R, reader=read_ints, *args, **kwargs):
    return [reader(f, *args, **kwargs) for i in range(R)]

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
                write_case(fo, i, res)

DEBUG = 'f'

from run import *
