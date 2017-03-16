#!/usr/bin/env python

import math

def inputs():
    return tuple(map(int, raw_input().split(' ')))

def sqrt(x):
    if x < 100:
        return long(math.sqrt(x))
    sx = str(x)
    if len(sx) % 2 == 1:
        sx = '0' + sx
    q = 0L
    l = 0L
    r = 0L
    for i in range(0, len(sx), 2):
        s = r*100 + long(sx[i:(i+2)])
        for temp in reversed(range(10)):
            if (20*q + temp)*temp <= s:
                break
        r = s - (20*q + temp)*temp
        q = 10*q + temp
    return q

def solve(X, Y, n):
    dist = abs(X) + abs(Y)
    max_dist = (n*(n+1))/2
    extra_dist = max_dist - dist
    if extra_dist < 0 or extra_dist % 2 != 0:
        return None
    if n == 0:
        return ''
    temp = solve(X, Y-n, n-1)
    if temp is not None:
        return temp + 'N'
    temp = solve(X-n, Y, n-1)
    if temp is not None:
        return temp + 'E'
    temp = solve(X, Y+n, n-1)
    if temp is not None:
        return temp + 'S'
    temp = solve(X+n, Y, n-1)
    if temp is not None:
        return temp + 'W'
    return None

(T,) = inputs()
for t in range(T):
    print "Case #%d:" % (t+1,),
    (X, Y) = inputs()
    dist = abs(X) + abs(Y)
    n = sqrt(2*dist)
    while True:
        temp = solve(X, Y, n)
        if temp is not None:
            print temp
            break;
        n += 1
