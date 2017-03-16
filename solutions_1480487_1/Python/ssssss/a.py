#!/usr/bin/python3

import sys
import math

def test(X,s,i,m):
    y = 1.0 - m;
    icost = s[i] + X*m
    for j in range(0, len(s)):
        if j == i: continue
        if s[j] < icost:
            y -= (icost - s[j])/X
            if y < 0:
                return True
    return False

def case(line):
    N = int(line.split()[0])
    j = [float(x) for x in line.split()[1:]]
    assert(N==len(j))
    X = sum(j)
    a = []
    for i in range(0, N):
        l = 0.0
        r = 1.0
        while r-l > 0.000000001:
            m = (r+l)/2
            if test(X,j,i,m):
                r = m
            else:
                l = m
        a.append(r)
    return " ".join([str(round(x*100,6)) for x in a])

T = int(sys.stdin.readline())
for i in range(1,T+1):
    r = case(sys.stdin.readline().strip())
    print("Case #%s: %s" % (i, r))
    

