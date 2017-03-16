#!/usr/bin/env python

def calc(a):
    for k in xrange(len(a)):
        if calc2(a, k): return True
    return False

def calc2(a, k):
    v = [0 for i in xrange(len(a))]
    b = [k]
    v[k] = 1
    while b:
        k = b.pop()
        for u in a[k]:
            if v[u]:
                return True
            b.append(u)
            v[u] = 1
    return False

T = input()

for i in xrange(T):
    N = input()
    a = []
    for j in xrange(N):
        x = [int(k) - 1 for k in raw_input().split()]
        a.append(x[1:])
    print 'Case #%d: %s' % (i + 1, 'Yes' if calc(a) else 'No')
