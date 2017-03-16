# coding: utf8
from __future__ import division

def scan():
    while True:
        for w in raw_input().split():
            yield w

words = scan()

def scans(num=-1):
    return (next(words) for i in xrange(num)) if num >= 0 else next(words)

def scani(num=-1):
    return (int(value) for value in scans(num)) if num >= 0 else int(scans())

def scanf(num=-1):
    return (float(value) for value in scans(num)) if num >= 0 else int(scans())

probs = [1.0] * 100000
corrprobs = [1.0] * 100000

#------------------------------------------------------------------------------
for case in xrange(1, scani() + 1):
    print "Case #%d:" % (case,),
    a, b = scani(2)
    mincost = b + 2
    bscount = 0
    i = 1
    prob = 1
    for p in scanf(a):
        prob *= p
        corrprobs[i] = prob
        probs[i] = p
        i += 1

    for i in xrange(0, a + 1):
        prob = corrprobs[a - i]
        corrcost = a - (a - i)
        corrcost += b - (a - corrcost) + 1
        misscost = corrcost + b + 1
        mincost = min(mincost, corrcost * prob + misscost * (1 - prob))

    print "%f" % mincost
