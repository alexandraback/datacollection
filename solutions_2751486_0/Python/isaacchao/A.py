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
    return ''.join(map(lambda x: '0' if x in vowel else '1', s))

[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    ans = 0
    # main

    name, n = gettoken()
    L = len(name)
    n = int(n)

    mask = toMask(name)

    sstr = "1" * n
    for i in xrange(L):
        for j in xrange(i, L):
            ans += 1 if sstr in mask[i:j + 1] else 0


    """
    curr_n = 0
    c = 0
    cs = []
    for m in mask:
        if not m:
            curr_n = 0
        else:
            curr_n += 1

        if curr_n >= n:
            c += 1
        cs.append(c)

    print cs

    ans = 0
    for i in xrange(0, len(mask) - n + 1):
        hm = cs[-1] - cs[i + n - 2]
        ans += hm
        print name[i:], hm
    """

    # main
    print "Case #%d: %d" % (cases, ans) # answer output
