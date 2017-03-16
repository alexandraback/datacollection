#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys, operator


def run(A, B, p):
    prob = reduce(operator.mul, p)
    case1 = (1 - prob) * (B+B-A+2) + prob * (B-A+1)

    prob = 1
    if len(p) > 1:
        prob = reduce(operator.mul, p[:-1])
    case2 = (1 - prob) * (B+B-A+4) + prob * (B-A+3)

    prob = 1
    if len(p) > 2:
        prob = reduce(operator.mul, p[:-2])
    case3 = (1 - prob) * (B+B-A+6) + prob * (B-A+5)
    
    case4 = 2 + B
    return min([case1, case2, case3, case4])
    
if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) > 1:
        fname = sys.argv[1]
        if fname != "-":
            f = open(fname)
    N = int(f.readline())
    for _num in xrange(N):
        A, B = map(int, f.readline().split())
        p = map(float, f.readline().split())
        ret = run(A, B, p)
        print "Case #%d: %f" % (_num+1, ret)
