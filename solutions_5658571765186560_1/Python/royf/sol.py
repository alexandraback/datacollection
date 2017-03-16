
import math
import itertools
import numpy as NP

################################################################################

def read_case(f):
    X, R, C = read_ints(f)
    return X, R, C

def solve_small(case):
    X, R, C = case
    if (R * C) % X != 0:
        return True
    if X > max(R, C):
        return True
    if (X + 1) // 2 > min(R, C):
        return True
    if X <= 3:
        return False
    if X == 4:
        return min(R, C) == 2
    if X == 5:
        return False
    if X == 6:
        return min(R, C) == 3
    return True

def solve_large(case):
    return solve_small(case)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%('RICHARD' if res else 'GABRIEL'))
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
