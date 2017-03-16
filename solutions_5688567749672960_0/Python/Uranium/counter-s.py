#!/usr/bin/env python

def solve(N):
    q = [(1, 1)]
    v = set([1])

    while len(q) > 0:
        n = q[0]
        q = q[1:]

        if n[0] == N:
            return n[1]

        n_1 = n[0]+1
        if n_1 not in v:
            v.add(n_1)
            q.append((n_1, n[1]+1))

        n_2 = int(str(n[0])[::-1].lstrip('0'))
        if n_2 not in v:
            v.add(n_2)
            q.append((n_2, n[1]+1))


T = int(raw_input())
for t in xrange(T):
    N = int(raw_input())
    print "Case #%d: %d" % (t+1, solve(N))
