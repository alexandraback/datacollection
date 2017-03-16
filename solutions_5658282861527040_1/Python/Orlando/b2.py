#!/usr/bin/env python

t = int(raw_input())

def fact(n, m):
    r = 1
    while n > m:
        r *= n
        n -= 1
    return r

def choose(n, k):
    if (k > n-k):
        return fact(n, k) / fact(n-k, 1)
    return fact(n, n-k) / fact(k, 1)

for caseno in xrange(1, t+1):
    a, b, k = map(int, raw_input().split())
    a, b = max(a, b), min(a, b)
    if (a <= k) or (b <= k):
        print "Case #%d: %d" % (caseno, a*b)
        continue
    i = a*k + k*(b-k)
    for j1 in xrange(k, a):
        for j2 in xrange(k, b):
            if j1 & j2 < k:
                i += 1
    print "Case #%d: %d" % (caseno, i)
