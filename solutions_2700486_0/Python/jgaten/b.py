#!/usr/bin/env python
import sys

def pyramid(size):
    # number of diamonds it takes to fill in a pyramid of given height (in number of diamonds)
    return 2 * size ** 2 + 3 * size + 1

def choose(n, r):
    res = 1
    for i in xrange(n-r+1,n+1):
        res *= i
    for i in xrange(1,r+1):
        res /= i
    return res

def count_combinations(m, k):
    # m diamonds falling, need >= k of them to fall to the right
    return sum(choose(m, i) for i in xrange(k,m+1))

def solve(n, x, y):
    x = abs(x) # WLOG

    # special case: only way to get x = 0 is by filling the pyramid
    if x == 0:
        if n < pyramid(y / 2):
            return 0.
        else:
            return 1.

    # assume the pyramid inside is filled in, and count the number of diamonds remaining to be placed
    m = n - pyramid((x + y)/2 - 1)
    if m < y + 1:
        # need at least y+1 diamonds to fall to the right
        return 0.
    if m > x + 2 * y:
        # at worst, fill the outer layer with (x+y) on the left, and y on the right.
        return 1.

    combs = count_combinations(m, y+1)
    print n, x, y, m, combs

    return combs / 2. ** m


if __name__ == '__main__':
    with open(sys.argv[1], 'rU') as fin, open(sys.argv[2], 'w') as fout:
        T = int(fin.readline())
        for case in xrange(1, T+1):
            print "Case #{0}:".format(case),

            n, x, y = map(int, fin.readline().split())

            soln = float(solve(n, x, y))
            print soln
            print >> fout, "Case #{0}: {1:.6}".format(case, soln)
