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

vowel = {
    'a': 1,
    'e': 1,
    'i': 1,
    'o': 1,
    'u': 1,
    }

def toMask(s):
    return map(lambda x: not x in vowel, s)

[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    # main

    X, Y = getints()
    ans = ""
    if X < 0:
        ans += "EW" * (-X)
    else:
        ans += "WE" * X

    if Y < 0:
        ans += "NS" * (-Y)
    else:
        ans += "SN" * Y

    # main
    print "Case #%d: %s" % (cases, ans) # answer output
