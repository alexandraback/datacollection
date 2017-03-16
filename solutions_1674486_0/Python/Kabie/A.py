#!/usr/bin/env python
# -*- coding: utf-8 -*-

from functools import reduce


def unpack(u, d):
    u.update(d.keys())
    for v in d.values():
        unpack(u, v)
    return u

def search(d):

    
    res = []
    for k, D in d.items():
        tmp = unpack(set([k]), D)
        for r in res:
            if tmp.intersection(r):
                return True
        res.append(tmp)

    return False


def solve(f):
    N = int( next(f) )
    cls = {i:{} for i in range(1, N+1)}
    for i in range(1, N+1):
        n, *M = map(int, next(f).split())

        for mi in M:
            cls[i][mi] = cls[mi]

    for c in cls:
        if len(cls[c])>1:
            if search(cls[c]):
                return "Yes"
    return "No"


with open("A-small.in") as IN:
    with open("A-small.out", 'w') as OUT:
        T = int(next(IN))

        for t in range(1, T+1):
            print("Case #{}: {}".format(t, solve(IN)), file=OUT)
