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

    # 0 = 0 0 0
    # 1 = 0 0 1
    # 2 = 1 1 0 -> 2 0 0   (2 mod 3)  N/3 + 1   N/3 + 2

    # 3 = 1 1 1 -> 0 1 2   (0 mod 3)  N/3       N/3 + 1
    # 4 = 1 1 2 -> 3 1 0 x (1 mod 3)  N/3 + 1   N/3 + 1
    # 5 = 2 2 1 -> 3 1 1   (2 mod 3)  N/3 + 1   N/3 + 2
    scores = getints()
    N, S, p, scores = scores[0], scores[1], scores[2], sorted(scores[3:], reverse=True)
    #print N, S, p, scores
    for score in scores:
        base, type = divmod(score, 3)

        base = base if type == 0 else base + 1
        surprise = base if type == 1 or score <= 1 else base + 1

        if base >= p:
            # no surprise got good score
            ans += 1
        elif S > 0 and surprise >= p:
            # a bit surprised
            ans += 1
            S -= 1
        else:
            # not surprised got bad score
            break
    
    # main
    print "Case #%d: %d" % (cases, ans) # answer output
