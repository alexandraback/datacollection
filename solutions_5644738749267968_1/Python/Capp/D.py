#!/usr/bin/env python

from sys import stdin
from numpy import array
from math import ceil

T = int(stdin.readline())

for t in range(T):
    N = int(stdin.readline())
    m1 = array(stdin.readline().split()).astype(float)
    m2 = array(stdin.readline().split()).astype(float)
    m1.sort()
    m2.sort()

    #print "m1 = ", m1
    #print "m2 = ", m1

    ret1 = N
    end = N-1
    for i in range(N):
        if m2[-1-i] < m1[end]:
            end -= 1
        else:
            ret1 -= 1
            pass
        pass

    ret2 = 0
    end = N-1
    for i in range(N):
        if m1[-1-i] < m2[end]:
            end -= 1
        else:
            ret2 += 1
            pass
        pass

    print "Case #%d:" % (t+1),
    print ret1, ret2
