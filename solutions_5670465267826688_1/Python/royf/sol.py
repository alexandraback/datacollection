
import math
import itertools
import numpy as NP

################################################################################

def read_case(f):
    L, X = read_ints(f)
    Z = read_letters(f)
    return L, X, Z

LU = {'1': 0, 'i': 1, 'j': 2, 'k': 3}

def mul(x, y):
    res = [
        ['1', 'i', 'j', 'k'],
        ['i', '-1', 'k', '-j'],
        ['j', '-k', '-1', 'i'],
        ['k', 'j', '-i', '-1']
    ][LU[x[-1]]][LU[y[-1]]]
    sign = '-' if (x[0] == '-') ^ (y[0] == '-') ^ (res[0] == '-') else ''
    return sign + res[-1]

def find_index(L, X, Z, target, reverse):
    x = '1'
    if reverse:
        r = range(L * X - 1, L * max(X - 4, 0), -1)
    else:
        r = range(L * min(X, 4) - 1)
    for i in r:
        if reverse:
            x = mul(Z[i % L], x)
        else:
            x = mul(x, Z[i % L])
        if x == target:
            return i

def solve_small(case):
    L, X, Z = case
    ii = find_index(L, X, Z, 'i', False)
    if ii is None:
        return False
    ik = find_index(L, X, Z, 'k', True)
    if ik is None:
        return False
    if ii >= ik:
        return False
    x = '1'
    for ii in range(ii + 1, min(ik, (ii // L) * L + L)):
        x = mul(x, Z[ii % L])
    ii += 1
    y = '1'
    for ik in range(ik - 1, max(ii, (ik // L) * L) - 1, -1):
        y = mul(Z[ik % L], y)
    if ik > ii:
        z = '1'
        for m in Z:
            z = mul(z, m)
        for t in range(((ik - ii) // L) % 4):
            x = mul(x, z)
    j = mul(x, y)
    return j == 'j'

def solve_large(case):
    return solve_small(case)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('YES' if res else 'NO')
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

DEBUG = 'i'

from run import *
