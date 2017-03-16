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

import copy

def dfs(e, v, i):
    eh = v[i]
    if eh == 2: return True
    if eh == 1: return False
    v[i] = 1
    for (j, _) in e[i].iteritems():
        lol = dfs(e, v, j)
        if lol: return True
    v[i] = 2
    return False

[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    ans = 0
    # main
    N = getint()
    edge = {}
    visit = {}
    for i in xrange(1, N + 1):
        edgei = {}
        for j in getints()[1:]:
            edgei[j] = True
        edge[i] = edgei
        visit[i] = 0

    haha = False
    for i in xrange(1, N + 1):
        d = copy.deepcopy(edge)
        v = copy.deepcopy(visit)
        lol = dfs(d, v, i)
        if lol:
            haha = True
            break

    # main
    print "Case #%d: %s" % (cases, "Yes" if haha else "No") # answer output

