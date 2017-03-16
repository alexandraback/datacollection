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

def brute(E, R, N, k, e, i = 0, v = 0):
    #print " " * i, e, i, v
    if i == len(k):
        return v

    vv = k[i]
    cand = []
    for j in xrange(min(e, E) + 1):
        cand.append(
            brute(E, R, N, k,

                  min(e - j + R, E),
                  i + 1,
                  v + j * vv
                  )
            )

    return max(cand)


# global data

[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    ans = 0
    # main

    E, R, N = getints()
    act = getints()

    # print E, R, N, act
    r2r = int(math.ceil(E / float(R)))

    ans = sum(act) * E if r2r == 1 else brute(E, R, N, act, E)

    # main
    print "Case #%d: %d" % (cases, ans) # answer output
