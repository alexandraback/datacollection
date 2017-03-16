
import math
import itertools
import numpy as NP

################################################################################

def read_case(f):
    N, M = read_ints(f)
    Z = read_arr(f, N, read_word)
    E = read_arr(f, M)
    return (N, M, Z, E)

def solve_small(case):
    (N, M, Z, E) = case
    if N == 1:
        return Z[0]
    n = {}
    for (i, j) in E:
        n.setdefault(i, set()).add(j)
        n.setdefault(j, set()).add(i)
    res = min(Z)
    i = Z.index(res)+1
    c = set([i])
    for ni in n.values():
        ni.discard(i)
    s = [i]
    o = [n[i]]
    while len(c) < N:
        r = {}
        for i in range(1, N+1):
            if i in c:
                continue
            r[i] = set(n[i])
        change = True
        while change:
            change = False
            for i in range(1, N+1):
                if i in c:
                    continue
                for j in n[i]:
                    if r[j] - r[i]:
                        change = True
                    r[i] |= r[j]
        i = max(i for i in range(len(o)) if i == 0 or any(len(r[j]) < N-len(c) for j in o[i]))
        (z, j, k) = min((Z[j-1], j, k) for k in range(i, len(o)) for j in o[k])
        res += z
        c.add(j)
        for ni in n.values():
            ni.discard(j)
        s = s[:k+1]
        o = o[:k+1]
        s.append(j)
        o.append(n[j])
    return res

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
