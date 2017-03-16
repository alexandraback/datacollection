#!/usr/bin/python3

import sys
import math

base = 1/math.pow(2,40)

ncases = int(sys.stdin.readline().strip())

for t in range(1, ncases+1):
    fractions = sys.stdin.readline().strip().split('/')
    p = int(fractions[0])
    q = int(fractions[1])

    possible = (p/q)/base
    if possible != round(possible):
        print("Case #{0}: impossible".format(t))
    else:
        mingen = math.ceil(math.log(q/p, 2))
        if mingen == 0:
            mingen = 1
        print("Case #{0}: {1}".format(t, mingen))
