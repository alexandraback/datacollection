#! /opt/local/bin/python

import sys, itertools, math

def getline(file=sys.stdin):
    return file.readline().strip()

def out(s):
    if True:
        print s

def getBest(total):
    return int(math.ceil(float(total) / 3.0))

def getBestSurprising(total):
    if total <= 0:
        return 0
    best = int(round(float(total) / 3.0) + 1)
    if best > 10:
        best = 10
    return best

def solve(casenum):
    inp = [int(x) for x in getline().split()]
    n = inp[0]
    s = inp[1]
    p = inp[2]
    t = inp[3:]
    yes = no = maybe = 0

    for tx in t:
        best = getBest(tx)
        if best >= p:
            yes += 1
        else:
            best = getBestSurprising(tx)
            if best >= p:
                maybe += 1
            else:
                no += 1

    answer = yes + min(s, maybe)
    print 'Case #%d: %s' % (casenum, answer)

cases = int(getline())
for case in xrange(cases):
    solve(case + 1)
