#!/usr/bin/python

import sys
from collections import defaultdict

f = open("large2.in","rb")
t = int(f.readline())
global res

def solve(s):
    b = s[0]
    m = s[1]
    d = pow(2, b-2) - m
    if d < 0:
        return None
    v = []
    n = pow(2, b-3)
    i = 1
    while i < b:
        if d >= n:
            v.append(i)
            d = d - n
        n = pow(2, b-3-i)
        i += 1
    matrix = [['0' for jj in range(b)] for ii in range(b)]
    if len(v) == 0:
        start = 0
    else:
        for ii in range(1, b, 1):
            if ii not in v:
                start = ii
                break
    for ii in range(b-1, start-1, -1):
        for jj in range(ii+1, b, 1):
            matrix[ii][jj] = '1'
    for ii in range(1, b, 1):
        if ii not in v:
            matrix[0][ii] = '1'
    return matrix

for i in range(t):
    s = f.readline().strip().split(" ")
    si = [int(x) for x in s]
    out = solve(si)

    if out:
        print "Case #%s: POSSIBLE" % (i+1)
        for ii in range(si[0]):
            print "".join(out[ii])
    else:
        print "Case #%s: IMPOSSIBLE" % (i+1)
