#!/usr/bin/env python3

################################################################################

def read_int():
    return int(input())

def read_words():
    return input().split()

def read_ints():
    return list(map(int,read_words()))

def read_floats():
    return list(map(float,read_words()))

################################################################################

import itertools
def findsubsets(S,m):
        return set(itertools.combinations(S, m))

from itertools import chain, combinations

def powerset(iterable):
    xs = list(iterable)
    return chain.from_iterable( combinations(xs,n) for n in range(len(xs)+1) )

def comp_reach(s):
    return set(map(lambda x: sum(x), set(powerset(denoms))))

def solve(c,d,v,denoms):
    full_range = set(range(1,v+1))
    drange = comp_reach(denoms)
    missing = full_range.difference(drange)
    result = 0
    while missing:
        denoms.append(sorted(missing)[0])
        drange = comp_reach(denoms)
        missing = full_range.difference(drange)
        result += 1


    return result

if __name__ == "__main__":
    T = read_int()
    for c in range(T):
        C,D,V = read_ints()
        denoms = read_ints()
        R = solve(C,D,V,denoms)
        print("Case #{}: {}".format(c+1,R))
