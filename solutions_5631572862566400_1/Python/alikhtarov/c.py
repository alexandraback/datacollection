#!/usr/bin/env python
#7 8 10 10 9 2 9 6 3 3
#
#
#5->1->7
#^-----+
#
#   4->8->2<=>9<-3
#0->6--^

def longest(fs, to, avoid):
    ans = 1
    for i in range(len(fs)):
        if fs[i] == to and i != avoid:
            t = longest(fs, i, to) + 1
            if t > ans:
                ans = t
    return ans
            

import sys
ls = sys.stdin.readlines()[1:]
C = 1
while len(ls) > 0:
    n = int(ls[0])
    fs = [int(x)-1 for x in ls[1].split()]
    ls = ls[2:]
    ans = 0
    for i in range(n):
        for j in range(i+1, n):
            if fs[i] == j and fs[j] == i:
                ans += longest(fs, i, j) + longest(fs, j, i)
    for i in range(n):
        d = {}
        j = i
        k = 0
        while j not in d:
            d[j] = k
            k += 1
            j = fs[j]
        if k - d[j] > ans:
            ans = k - d[j]
    print "Case #%d: %d" % (C, ans)
    C += 1
