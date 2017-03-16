#!/usr/bin/env python

import sys
from scipy.stats.distributions import binom

def xytotri(x):
    s = (x)/2
    n = 0
    t = 0
    for i in xrange(0, s):
        t += 2*n + 1
        n += 2

    return t
    
assert xytotri(0) == 0
assert xytotri(2) == 1
assert xytotri(4) == 6
assert xytotri(6) == 15
assert xytotri(8) == 28

def solve(N, X, Y):
    X = abs(X)
    
    z = xytotri(X + Y)
    #print "%s, %s, %s, %s" % (N, X, Y, z)

    if z >= N:
        return 0

    #print xytotri(X+Y+2)

    if xytotri(X+Y+2) <= N:
        return 1

    rem = N - z

    #print "%s, %s, %s, %s, %s" % (N, X, Y, z, rem)
    #print  (((Y/2)+1)*2)+1
    #if X == 0 and rem < (((Y/2)+1)*2)+1:
    if X == 0 and xytotri(X+Y+2) > N:
        return 0

    #print "n, z, x, y, rem", N, z, X, Y, rem

    #return 1-normal_estimate((Y+1)-1, 0.5, rem)

    if rem - (xytotri(X+Y+2) - z - 1)/2 > Y:
        return 1

    return 1-binom.cdf((Y+1)-1, rem, 0.5)


with open(sys.argv[1]) as fobj:
    T = int(fobj.readline())
    for t in range(0, T):
        N, X, Y = fobj.readline().strip().split()
        X = int(X)
        Y = int(Y)
        N = int(N)
        #sizes = [int(x) for x in fobj.readline().split()]
        #assert len(sizes) == N
        #print N, X, Y
        print "Case #%d: %0.10f" % (t+1, solve(N, X, Y))
        #print "Case #%d: %0.10f" % (t+1, solve(N, -X, Y))
#    lines = fobj.readlines()
#    lines = [line.strip() for line in lines]

#print N, lines
