#!/usr/bin/env python

import numpy as np
import sys

def decide(a, A, b, B):
    if A.size <= 0 or B.size <= 0:
        return 0
    if A[0] == B[0]:
        x = min(a[0], b[0])
        a[0] -= x
        b[0] -= x
        astart = 0 if a[0] > 0 else 1
        bstart = 0 if b[0] > 0 else 1
        y = x + decide(a[astart:], A[astart:], b[bstart:], B[bstart:])
        a[0] += x
        b[0] += x
        return y

    return max(decide(a[1:], A[1:], b, B), decide(a, A, b[1:], B[1:]))



def doTestcase():
    N, M = [int(x) for x in sys.stdin.readline().split()]
    allA = np.array([int(x) for x in sys.stdin.readline().split()])
    a, A = allA[0::2], allA[1::2]
    allB = np.array([int(x) for x in sys.stdin.readline().split()])
    b, B = allB[0::2], allB[1::2]
    return decide(a, A, b, B)



for tc in xrange(1, int(sys.stdin.readline()) + 1):
    print "Case #{0}:".format(tc), doTestcase()

