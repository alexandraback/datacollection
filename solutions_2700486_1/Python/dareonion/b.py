#!/usr/bin/env pypy
from __future__ import division
import math
import sys

def nCr(n,r):
    f = math.factorial
    return f(n) // f(r) // f(n-r)

def get_result(N, X, Y):
    X = abs(X)
    # make sure x and y are valid
    if (X+Y) % 2 != 0 or Y < 0:
        return 0.0
    # special case X = 0
    if X == 0:
        if N < (Y+1)*(Y+2)/2:
            return 0.0
        else:
            return 1.0

    # find size of base
    base = (X+Y-1)*(X+Y)/2
    if N <= base:
        return 0.0

    k = N - base
    if k >= (X+Y)+(Y+1):
        return 1.0

    if k <= Y:
        return 0.0

    s = 0
    for i in xrange(k, Y, -1):
        s += nCr(k, i)
    return s / 2**k

def main():
    fname, gname = sys.argv[1:]
    with open(fname) as f, open(gname, 'w') as g:
        # number of test cases
        T = int(f.readline().strip())
        for i in xrange(T):
            # number of falling diamonds, and coordinates
            N, X, Y = map(int, f.readline().strip().split())
            result = float(get_result(N, X, Y))
            g.write("Case #{0}: {1}\n".format(i+1, result))

if __name__ == "__main__":
    status = main()
    sys.exit(status)
