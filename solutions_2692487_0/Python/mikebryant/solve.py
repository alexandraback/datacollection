#!/usr/bin/env python

import sys


def attempt(x, sizes):
    #print "Attempting", x, sizes
    r1 = solve(x, [x-1] + sizes)
    r2 = solve(x, sizes[1:])
    if r1 > r2:
        return r2+1
    else:
        return r1+1

def solve(A, sizes):
    sizes.sort()
    ops = 0

    while sizes:
        if sizes[0] < A:
            #print "Eaten", sizes[0]
            A += sizes[0]
            sizes = sizes[1:]
        elif len(sizes) == 1:
            ops += 1
            sizes = sizes[1:]
        elif A == 1:
            ops += 1
            sizes = sizes[1:]
        else:
            return ops + attempt(A, sizes)
    return ops


with open(sys.argv[1]) as fobj:
    T = int(fobj.readline())
    for t in range(0, T):
        A, N = fobj.readline().strip().split()
        A = int(A)
        N = int(N)
        sizes = [int(x) for x in fobj.readline().split()]
        assert len(sizes) == N
        #print A, sizes
        print "Case #%d: %d" % (t+1, solve(A, sizes))
#    lines = fobj.readlines()
#    lines = [line.strip() for line in lines]

#print N, lines
