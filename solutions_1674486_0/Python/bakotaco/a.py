#!/usr/bin/env python

from sys import stdin, stderr

def debug(args):
    print >> stderr, args

for tc in xrange(1, int(stdin.readline()) + 1):
    debug("***")
    n = int(stdin.readline())
    edges = []
    diamond = False
    for i in xrange(0, n):
        input = [int(w) for w in stdin.readline().split()]
        if input[0] > 0:
            edges.append([j - 1 for j in input[1:]])
        else:
            edges.append([])
    for i in xrange(0, n):
        debug(i)
        reachable = []
        heads = edges[i][:]
        while heads:
            head = heads.pop()
            reachable.append(head)
            for dest in edges[head]:
                heads.append(dest)
        debug("reachable: %s" % (reachable))
        if len(reachable)!=len(set(reachable)):
            diamond = True
    print 'Case #%d: %s' % (tc, "Yes" if diamond else "No")
