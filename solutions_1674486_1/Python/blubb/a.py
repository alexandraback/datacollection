#!/usr/bin/env python

import numpy as np
import sys

def doTestcase():
    N = int(sys.stdin.readline())
    edges = []
    for i in xrange(N):
        edges.append([int(x) - 1 for x in sys.stdin.readline().split()[1:]])

    for c in xrange(N):
        nodes = np.zeros(N)
        nodes[c] = True
        tovisit = []
        tovisit.extend(edges[c])
        while len(tovisit) > 0:
            a = tovisit[0]
            if nodes[a]:
                return "Yes"
            nodes[a] = True
            tovisit = tovisit[1:]
            tovisit.extend(edges[a])

    return "No"



for tc in xrange(1, int(sys.stdin.readline()) + 1):
    print "Case #{0}:".format(tc), doTestcase()

