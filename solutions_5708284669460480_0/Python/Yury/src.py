#!/usr/bin/python3

import sys
from itertools import *
from functools import *
from pprint import pprint
from collections import defaultdict


def gen_perms(ks, S):
    if S == 1:
        for k in ks:
            yield k
    else:
        for k in ks:
            for w in gen_perms(ks, S-1):
                yield k + w

def solve(S, ks, tg):
    kks = defaultdict(float)
    for k in ks:
        kks[k] += 1.0/len(ks)
    #perr(kks)

    tot = 0.0
    tot2 = 0
    ma2 = 0
    perr(ks, tg)
    for kk in gen_perms(ks, S):
        k = ''.join(kk)
        count = 0
        for i in range(S+1-len(tg)):
            if k[i:i+len(tg)] == tg:
                count += 1
        #perr(k, count, k[0:len(tg)] == tg)
        tot += count
        tot2 += 1
        ma2 = max(ma2, count)
    perr(ma2, tot, tot2)
    return ma2 - tot / tot2


def parse(fin):
    K,L,S = tuple(int(x) for x in fin.readline().split())
    ks = fin.readline().strip()
    tg = fin.readline().strip()
    assert len(ks)==K
    assert len(tg)==L
    return S,ks,tg

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
