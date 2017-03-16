#!/usr/bin/python

import sys
from collections import deque

def is_diamond(c, hier):
    seen = set()
    queue = deque(hier[c])
    while queue:
        par = queue.popleft()
        if par in seen:
            return True
        else:
            seen.add(par)
            queue.extend(hier[par])
    return False

def case(hier):
    for c, parents in hier.iteritems():
        if len(parents) > 1:
            if is_diamond(c, hier):
                return True
    return False

def main():
    T = int(sys.stdin.readline())
    for x in xrange(1, T+1):
        N = int(sys.stdin.readline())
        hier = {}
        for c in xrange(1, N+1):
            row = map(int, sys.stdin.readline().split())
            n = row[0]
            parents = row[1:]
            assert n == len(parents)
            hier[c] = parents
        print "Case #%d: %s" % (x, "Yes" if case(hier) else "No")

main()
