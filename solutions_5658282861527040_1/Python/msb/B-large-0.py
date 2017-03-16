#!/usr/bin/env python

def solve(a, b, k):
    if a <= k and b <= k:
        print a * b
    elif a <= k:
        print a * k + (b - k) * a
    elif b <=k :
        print b * k + (a - k) * b
    else:
        count = k * k + (b - k) * k + (a - k) * k
        for i in xrange(k, b):
            for j in xrange(k, a):
                if i & j < k:
                    count += 1
        print count

for case in xrange(int(raw_input())):
    print "Case #%d:" % (case+1),
    a, b, k = map(int, raw_input().split())
    solve(a, b, k)
