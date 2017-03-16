#! /usr/bin/env python
import sys, re
import operator as op
import math

""" START TEMPLATE JCHAOISAAC """

# some reading functions
lolfile = open(sys.argv[1]) # open file
getline = lambda: lolfile.readline().strip()
gettoken = lambda: re.split("\s+", getline())
getint = lambda: int(getline())
getints = lambda: map(int, gettoken())

# number theory / combinatorics
product = lambda l: reduce(op.mul, l) if l else 1
factorial = lambda n: product(xrange(n, 1, -1))
nPr = lambda n, r: product(xrange(n, n - r, -1))
nCr = lambda n, r: nPr(n, r) / factorial(r)
nMr = lambda l: factorial(sum(l)) / product(map(factorial, l))

""" END TEMPLATE JCHAOISAAC """

# global data

def tri(n):
    return (n * (n - 1)) >> 1

def brute(n, y, m, a, b):
    if n == 0:
        return (1 if a >= y else 0, 1)

    ok1 = 0
    total1 = 0
    ok2 = 0
    total2 = 0
    if a <= m:
        ok1, total1 = brute(n - 1, y, m, a + 1, b)

    if b <= m:
        (ok2, total2) = brute(n - 1, y, m, a, b + 1)

    return (ok1 + ok2, total1 + total2)


def ladder(N, x, y):
    l2 = (x + y)
    l = l2 / 2

    t1 = tri(l2)
    t2 = tri(l2 + 2)
    
    if N >= t2:
        return 1.0

    if N <= t1:
        return 0.0

    # tip
    if x == 0:
        return 0.0

    n = N - t1

    side = (t2 - t1 - 1) >> 1
    #if n >= side + y + 1:
    #    return 1.0
    

    #print N, x, y, t1, t2, n

    if n < y + 1:
        return 0.0

    (ok, total) = brute(n, y + 1, side, 0, 0)
    #print ok, total
    return ok / float(total)
    

# global data

[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    # main

    N, X, Y = getints()
    c = ladder(N, X, Y)

    # main
    print "Case #%d: %f" % (cases, c) # answer output
