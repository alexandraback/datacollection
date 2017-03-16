#!/usr/bin/env python
# -*- coding: utf-8 -*=

from math import factorial
from functools import reduce

def get_recs(n):
    sn = str(n)
    return set(map(int, (s for s in (sn[i:]+sn[:i] for i in range(len(sn))) if not s.startswith('0'))))

def init():
    for i in Numbers:
        if not Numbers[i]:
            recs = get_recs(i)
            for rec in recs:
                if Numbers.get(rec) is not None:
                    Numbers[rec] = recs

def solve(a, b):
    rang = {i:False for i in range(a, b+1)}

    result = 0
    for i in rang:
        if not rang[i]:
            recs = Numbers[i].copy()
            for rec in Numbers[i]:
                if rec in rang:
                    rang[rec] = True
                else:
                    recs.discard(rec)
            if len(recs)>1:
                result += len(recs)*(len(recs)-1)//2

    return result


if __name__ == '__main__':

    Numbers = {i:False for i in range(20000+1)}
    init()

    OUT = open('C-small.out','w')
    IN = open('C-small.in').__next__
    T = range(1, int(IN())+1)
    for case in T:
        A, B =map(int, IN().split())
        result = solve(A, B)
        print("Case #{}: {}".format(case, result), file=OUT)
        print("Case #{}: {}".format(case, result ))
