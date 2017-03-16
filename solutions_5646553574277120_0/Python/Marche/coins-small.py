#!/usr/bin/python3

import sys
from functools import lru_cache

DEBUG = True
def debug(*s):
    if DEBUG:
        print(*s, file=sys.stderr)

@lru_cache()
def feasible(v, den):
    if v == 0:
        return True
    elif len(den) == 0 or v < 0:
        return False
    for d in den:
        newden = list(den)
        newden.remove(d)
        if feasible(v-d, tuple(newden)):
            return True
    return False

def check(start, end, den):
    debug(den)
    lmin = end
    for v in range(start, end+1):
        if not feasible(v, den):
            for d in (0,) + den:
                if d <= v and v-d not in den:
                    newden = den + (v-d,)
                    n = check(v, end, newden)
                    if n < lmin:
                        lmin = n
            return lmin
    return len(den)

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T+1):
        C, D, V = map(int, input().split())
        den = []
        for x in input().split():
            den.extend([int(x)] * C)
        den = tuple(den)
        result = check(1, V, den) - len(den)


        print("Case #{}: {}".format(case, result))
        print("Case #{}: {}".format(case, result), file=sys.stderr)
