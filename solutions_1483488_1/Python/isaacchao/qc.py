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

numdigits = lambda n: int(math.log10(n)) + 1

""" END TEMPLATE JCHAOISAAC """

mr = {}
# global data
def findMinRot(n):
    global mr
    if n in mr: return

    d = numdigits(n)
    top = 10 ** (d - 1)
    small, y = n, n
    group = [y]
    for i in xrange(d - 1):
        y, l = divmod(y, 10)
        if l == 0:
            continue
        y += l * top
        group.append(y)
        if y < small:
            small = y

    for num in group:
        mr[num] = small
        
for x in xrange(1, 2000001 + 1):
    findMinRot(x)

counts = {}
for n in xrange(10):
    counts[n] = (n * (n - 1)) >> 1

#print mr

# global data

[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    ans = 0
    # main

    A, B = getints()
    group = {}
    for n in xrange(A, B + 1):
        r = mr[n]
        if r in group:
            group[r] += 1
        else:
            group[r] = 1

    ans = sum([counts[x] for x in group.itervalues()])

    # main
    print "Case #%d: %d" % (cases, ans) # answer output
