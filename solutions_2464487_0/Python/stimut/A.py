#!/usr/bin/env python

def memoize(func):
    cache = {}
    @wraps(func)
    def wrap(*args):
        if args not in cache:
            cache[args] = func(*args)
        return cache[args]
    return wrap


def read_ints():
    return [int(x) for x in input().split()]

T = int(input())

for case in range(T):
    print("Case #", case+1, ": ", sep='', end='')

    r, t = read_ints()

    rings = 0
    paint_needed = (r+1)*(r+1) - (r)*(r)
    while paint_needed <= t:
        #print(r, t)
        t -= paint_needed
        r += 2
        rings += 1
        paint_needed = (r+1)*(r+1) - (r)*(r)

    print(rings)

