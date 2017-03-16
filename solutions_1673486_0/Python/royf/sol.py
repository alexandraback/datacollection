
import itertools
import math
import numpy

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
                write_case(fo, i, res)

################################################################################

def read_case(f):
    N = read_int(f)
    M = read_int(f)
    L = read_arr(f, M)
    return (N, M, L)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

FAIL = 'IMPOSSIBLE'

def solve_small(case):
    (N, M, L) = case
    malt = []
    unmalt = []
    for l in L:
        malt.append(set(l[i] for i in range(1, len(l), 2) if l[i+1]))
        unmalt.append(set(l[i] for i in range(1, len(l), 2) if not l[i+1]))
    res = set()
    for i in range(M):
        res |= malt[i]-unmalt[i]
##    dbg('res')
    for i in range(M):
        if not (malt[i]&res) and not (unmalt[i]-res):
            return FAIL
    return ' '.join('%d'%(x in res) for x in range(1, N+1))

solve_large = solve_small

##def solve_large(case):

practice = True
DEBUG = 'i'

from run import *
