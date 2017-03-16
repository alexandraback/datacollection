#!/usr/bin/env python

import sys


def inverse(n):
    return int("".join(reversed(list(str(n)))))

from collections import deque

def solve(N):
    q = deque([(1, 1)])
    best = N
    visited = set([1])
    while q:
        n, s = q.popleft()
        if N == n:
            best = min(best, s)
            break
        nxt, inv = n+1, inverse(n)
        if nxt not in visited:
            q.append((nxt, s+1))
            visited.add(nxt)
        if inv not in visited:
            q.append((inv, s+1))
            visited.add(inv)
    return best

for i,ln in enumerate(open(sys.argv[1], 'r').readlines()):
    ln = ln.strip().split()
    if i == 0: continue
    case = i
    N = int(ln[0])
    print "Case #%d: %d" % (case, solve(N))
