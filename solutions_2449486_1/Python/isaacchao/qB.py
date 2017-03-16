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
    ans = 0
    # main

    N, M = getints()

    g = []
    for _ in xrange(N):
        g.append(getints())
    gt = [list(x) for x in zip(*g)]

    gmax = map(max, g)
    gtmax = map(max, gt)

    #print g, gt
    #print gmax, gtmax
    valid = True
    for n in xrange(N):
        for m in xrange(M):
            v = g[n][m]
            if v < gmax[n] and v < gtmax[m]:
                valid = False
                break
        if not valid:
            break

    # main
    print "Case #%d: %s" % (cases, 'YES' if valid else 'NO') # answer output
