import sys
from math import *
from collections import *


def line():
    return sys.stdin.readline()


def solve(vals):
    #avals_orig = avals[:]

#    used = [0 for x in avals]
#    bused = [0 for x in avals]

    vals.sort(key=lambda (b,a): (b,-a))

    stars = 0
    steps = 0
    i = 0
    while i < len(vals):
        if vals[i][0] <= stars:
            used = (vals[i][1] == -1)
            stars += 2 - int(used)
            steps += 1
            vals[i] = (vals[i][0], -1)
            i += 1
        else:
            found = False
            for j in range(len(vals)-1,i-1,-1):
            #for j in range(0, len(vals)):
                if vals[j][1] != -1 and vals[j][1] <= stars:
                    steps += 1
                    stars += 1
                    vals[j] = (vals[j][0], -1)
                    found = True
                    break
            if not found:
                return "Too Bad"

    return steps


tc = int(line())
for i in range(1, tc+1):
    n = int(line())
    vals, bvals = [], []
    for j in range(n):
        a, b = [int(t) for t in line().split()]
        vals.append((b, a))



    print "Case #%s: %s" % (i, solve(vals))
