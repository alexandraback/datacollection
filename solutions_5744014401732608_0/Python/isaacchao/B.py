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

[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    ans = 0

    B, M = getints()
    N = 2 ** (B - 2)
    if M > N:
        print "Case #%d: IMPOSSIBLE" % (cases) # answer output
        continue

    print "Case #%d: POSSIBLE" % (cases) # answer output
    init = [['1' if i > j else '0' for i in xrange(B)] for j in xrange(B)]

    if M < N:
        i = 1
        M -= 1
        while i < B:
            M, r = divmod(M, 2)
            init[i][-1] = '0' if r == 0 else '1'
            i += 1
        
    print '\n'.join([''.join(r) for r in init])
