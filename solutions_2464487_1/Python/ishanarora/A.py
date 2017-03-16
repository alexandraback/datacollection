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

(T,) = inputs()
for i in range(T):
    print "Case #%d:" % (i+1,),
    (r, t) = inputs()
    print (sqrt((2*r - 1)**2 + 8*t) - (2*r - 1))/4
