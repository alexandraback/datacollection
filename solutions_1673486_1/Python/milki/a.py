#!/usr/bin/env python
import sys

n = int(raw_input())
for t in range(n):
    a, b = map(int, raw_input().split())
    p = [1] + [float(i) for i in raw_input().split()]

    res = 1e9
    prod_p = 1.0
    m = 1.0 #10 ** (len(p)-1)
    for i in xrange(1, len(p)):
        prod_p = prod_p * p[i]
        if i <= a:
            # backspace, correct
            t1 = (a-i + b-i + 1)
            # backspace, incorrect
            t2 = (a-i+b-i+1 + b+1)
            res = min(res, prod_p * t1 + (m-prod_p) * t2)

    # keep typing
    res = min(res, prod_p * (b-a+1) + (m-prod_p) * (b-a+1 + b+1))

    # enter right away
    res = min(res, 1+b+1)

    print "Case #%d: %.6f" % (t+1, res)
