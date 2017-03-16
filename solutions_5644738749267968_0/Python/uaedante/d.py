#!/usr/bin/python
import os, sys

fn = sys.stdin

total = int(fn.readline())

for case in range(1, total + 1):
    n = eval(fn.readline())
    x = fn.readline().split()
    y = fn.readline().split()
    for i in range(0, n):
        x[i] = eval(x[i])
        y[i] = eval(y[i])
    x.sort()
    y.sort()
    def count(x, y):
        usex = set()
        ret = 0
        for i in range(0, n):
            for j in range(0, n):
                if x[j] > y[i] and not j in usex:
                    ret += 1
                    usex.add(j)
                    break
        return ret
        
    print "Case #%d: %d %d" % (case, count(x, y), n - count(y, x))
