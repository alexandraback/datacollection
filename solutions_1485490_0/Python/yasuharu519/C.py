#!/usr/bin/env python
# -*- coding:utf-8 -*-

import sys, os
import operator
import itertools

TEMPLATE = "Case #%d: %d"

def decode(r):
    ans = [int(x) for x in r.readline().rstrip().split()]
    return (ans[0], ans[1])

def decodeanother(r):
    Aset = [int(x) for x in r.readline().rstrip().split()]
    Bset = [int(x) for x in r.readline().rstrip().split()]
    return (Aset, Bset)

def solve(N, M, A, B):
    a = [A[x] for x in range(len(A)) if x %2 == 0]
    b = [B[x] for x in range(len(B)) if x %2 == 0]
    A = [A[x] for x in range(len(A)) if x %2 == 1]
    B = [B[x] for x in range(len(B)) if x %2 == 1]
    table = dict()
    return lcs(A, B, a, b, table)

def lcs(xs, ys, valx, valy, table):
    if (tuple(xs), tuple(ys), tuple(valx), tuple(valy)) in table.keys():
        return table[(tuple(xs), tuple(ys), tuple(valx), tuple(valy))]
    if xs == [] or ys == []:
        ret = 0
    elif xs[-1] == ys[-1]:
        if valx[-1] > valy[-1]:
            ret = max(lcs(xs, ys[:-1], valx[:-1] + [valx[-1] - valy[-1]], valy[:-1], table) + min(valx[-1], valy[-1]),
                lcs(xs[:-1], ys[:-1], valx[:-1], valy[:-1], table) + min(valx[-1], valy[-1]))
        elif valy[-1] > valx[-1]:
            ret = max(lcs(xs[:-1], ys, valx[:-1], valy[:-1] + [valy[-1] - valx[-1]], table) + min(valx[-1], valy[-1]),
                lcs(xs[:-1], ys[:-1], valx[:-1], valy[:-1], table) + min(valx[-1], valy[-1]))
        else:
            ret = lcs(xs[:-1], ys[:-1], valx[:-1], valy[:-1], table) + min(valx[-1], valy[-1]) 
    else:
        ret = max(lcs(xs[:-1], ys, valx[:-1], valy, table),
                lcs(xs, ys[:-1], valx, valy[:-1], table))
    table[(tuple(xs), tuple(ys), tuple(valx), tuple(valy))] = ret
    return ret

if __name__ == "__main__":
    filename = sys.argv[1]
    with open(filename) as r:
        T = int(r.readline().rstrip())
        for i in xrange(T):
            N, M = decode(r)
            A, B = decodeanother(r)
            ans = solve(N, M, A, B)
            print TEMPLATE % (i + 1, solve(N, M, A, B))
