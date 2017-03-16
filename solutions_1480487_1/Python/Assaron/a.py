#!/usr/bin/python

from sys import *

T = int(stdin.readline().strip())


def get_ans(i, s):

    n = len(s)

    #print "n = %d" % n
    def ok(val):
        def need_votes(j):
            #print i, j
            return j != i and s[j] < s[i] + val

        x = sum(map(lambda j: s[i] + val - s[j], filter(need_votes, xrange(n))))
        return x > 1 - val

    lo = 0.
    hi = 1.
    for t in xrange(30):
        mid = (hi + lo)/2
        if ok(mid):
            hi = mid
        else:
            lo = mid
    return mid

for k in xrange(1, T + 1):
    stderr.write("%d\n" % k)
    l = stdin.readline()
    (n, s) = l.strip().split(" ", 1)
    n = int(n)
    s = map(int, s.split())
    S = sum(s)
    s = map(lambda x : float(x) / S, s)

    ans = map(lambda i: get_ans(i, s), xrange(n))

    print "Case #%d: %s" % (k, " ".join(map(lambda f: "%.9f" % (f * 100.), ans)))
