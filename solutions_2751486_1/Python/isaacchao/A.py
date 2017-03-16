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
    return map(lambda x: not  x in vowel, s)

[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    ans = 0
    # main

    name, n = gettoken()
    L = len(name)
    n = int(n)

    mask = toMask(name)

    """
    sstr = "1" * n
    for i in xrange(L):
        for j in xrange(i, L):
            ans += 1 if sstr in mask[i:j + 1] else 0
    """

    curr_n = 0
    prev = -1
    for i, m in enumerate(mask):
        if not m:
            curr_n = 0
        else:
            curr_n += 1

        if curr_n >= n:
            j = i - n + 1 # start index, to i
            endL = L - 1 - i + 1
            startL = j - prev

            #print startL, endL, startL * endL
            ans += endL * startL
            prev = j

    # main
    print "Case #%d: %d" % (cases, ans) # answer output
