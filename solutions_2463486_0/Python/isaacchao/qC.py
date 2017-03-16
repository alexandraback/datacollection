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

nl = [
    ('0', 0),
    ('1', 1),
    ('2', 4),
    ('3', 9),
    ]

def isPalindrome(x):
    return x == x[::-1]

def sqIsPalindrome(x):
    v = int(x)
    return isPalindrome(str(v * v))

def makeEP(x):
    return x + x[::-1]

def makeOP(x):
    return x + x[:-1][::-1] 

N = 50
sol = []
def findPalindrome(p, s, ls):
    lp = len(p)

    if (lp * 2 <= N) and (s + ls) * 2 < 10:
        v = int(makeEP(p))
        vp = str(v * v)
        if isPalindrome(vp):
            sol.append(vp)
            #print vp

    if (lp * 2 - 1 <= N) and (s * 2 + ls < 10):
        v = int(makeOP(p))
        vp = str(v * v)
        if isPalindrome(vp):
            sol.append(vp)
            #print vp
    else:
        return

   
    for (x, y) in nl:
        findPalindrome(p + x, s + ls, y)

findPalindrome("1", 0, 1)
findPalindrome("2", 0, 4)
findPalindrome("3", 0, 9)


sol = sorted(map(int, sol))
lol = zip(sol, sol[1:])
sl = len(sol)

#print sol
def findN(v, a=0, b=sl):
    while a < b:
        m = (a + b) / 2
        l, h = lol[m]

        #print a, m, b
        #print '    ', l, v, h

        if v >= h:
            a = m + 1
        elif v < l:
            b = m
        else:
            return m + 1
    return 0


# global data

[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    ans = 0
    # main

    a, b = getints()
    ans = findN(b) - findN(a - 1)

    # main
    print "Case #%d: %s" % (cases, ans) # answer output
