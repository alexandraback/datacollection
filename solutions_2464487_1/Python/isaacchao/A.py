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

    r, t = getints()

    # area of 1cm thick ring starting radius r
    # A = pi (r + 1)^2 - pi r^2 =  (2r + 1)pi 
    # V = 2r + 1

    # starting r
    #   [2r + 1] + [2(r + 2) + 1] + ... + [2(r + 2(k - 1)) + 1]
    # = k(2r + 1) + 4(1 + ... + (k - 1))
    # = k(2r + 1) + 2(k - 1)k
    # = 2k^2 - 2k  + kR

    # 0 = 2k^2 - k(2 - R) - t
    # k = {(2 - R) + sqrt[ (2 - R)^2 + 8t ] } / 4
    R = 2 * r + 1
    R2 = 2 - R
    c = int((R2 + math.sqrt(R2 * R2 + 8 * t)) / 4.0) 
    while c * (2 * c - 2 + R) > t:
        c -= 1

    # main
    print "Case #%d: %d" % (cases, c) # answer output
