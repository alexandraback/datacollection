from bisect import bisect_left
import math

import sys

cases = long(sys.stdin.readline())

def fun(n, r, t):
    return (n+1) * (2*n + 2*r + 1) > t

for case in xrange(cases):
    line = sys.stdin.readline()
    line = line.split(' ')
    r = float(line[0])
    t = float(line[1])
    n = 0

    # print math.sqrt(4.0*r*r - 4.0*r + 8.0*t + 1.0)/4.0
    # n = ((2.0*r+3.0) + math.sqrt(4.0*r*r - 4.0*r + 8.0*t + 1.0))/4.0

    while True:
        if (n+1) * (2*n + 2*r + 1) > t:
            break
        n += 1
    print 'Case #'+str(case+1)+': '+str(n)
