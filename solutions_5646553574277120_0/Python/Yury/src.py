#!/usr/bin/python3

import sys
from itertools import *
from functools import *
from pprint import pprint
from collections import defaultdict


def gen_sels(N):
    if N == 1:
        yield [False]
        yield [True]
    else:
        for ss in gen_sels(N-1):
            yield ss + [False]
            yield ss + [True]

def solve(C, V, ds):
    vs = set()

    for ss in gen_sels(len(ds)):
        vs.add(sum(i for i in compress(ds, ss)))

    #vs.remove(0)

    if C!=1:
        return None

    #perr(vs)

    es = set(ds)
    for i in range(1, V+1):
        if i in vs:
            continue
        vvs = set(i+v for v in vs)
        vs |= vvs
        es.add(i)
    return len(es) - len(ds)


def parse(fin):
    C, D, V= tuple(int(x) for x in fin.readline().split())
    ds = tuple(int(x) for x in fin.readline().split())
    assert len(ds)==D
    return C, V, ds

def print_result(res):
    return res

def gen_input(fin):
    T = int(fin.readline())
    for idx in range(1, T+1):
        #err('Case {}'.format(i))
        yield idx, parse(fin)

def main():
    for idx, inp_data in gen_input(sys.stdin):
        result_data = print_result(solve(*inp_data))
        print('Case #{}: {}'.format(idx, result_data))

def debug(fname, *cases):
    with open(fname) as fin:
        for idx, inp_data in gen_input(fin):
            if idx not in cases:
                continue
            print('Case: {}'.format(idx))
            print('Input: {!r}'.format(inp_data))
            solved = solve(*inp_data)
            print('Solved: {!r}'.format(solved))
            print('Printed: {}'.format(print_result(solved)))

def err(*m):
    print(*m, file=sys.stderr)

def perr(*m):
    pprint(m, stream=sys.stderr)

if __name__ == '__main__':
    main()
