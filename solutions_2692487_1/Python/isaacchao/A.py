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


""" END TEMPLATE JCHAOISAAC """

# global data



# global data

[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    # main

    A, N = getints()
    m = getints()
    m = sorted(m)

    def nReach(n, m):
        if n <= 1: return (None, None)
        c = 0
        while n <= m:
            n += n - 1
            c += 1
        return (c, n)

    def recur(n, i, l, s):
        if len(l) == i:
            return s

        f = l[i]
        if n > f:
            return recur(n + f, i + 1, l, s)

        # n <= f
        (ss, nn) = nReach(n, f)
        #if ss == 1:
        #    return recur(nn + f, i + 1, l, s + 1)

        s2 = recur(n, i + 1, l, s + 1)
        if nn == None:
            return s2

        s1 = recur(nn + f, i + 1, l, s + ss)
        return min(s1, s2)

    c = recur(A, 0, m, 0)

    # main
    print "Case #%d: %d" % (cases, c) # answer output
