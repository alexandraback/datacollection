#!/usr/bin/env python

import sys
from collections import defaultdict
from itertools import permutations, product


def solve(J, P, S, K):
    result0 = []
    for j in xrange(J):
        for PS, SHS in product(permutations(xrange(P)), permutations(xrange(S))):
            result = []
            jp = defaultdict(int)
            js = defaultdict(int)
            ps = defaultdict(int)
            for p in PS:
                for s in SHS:
                    oops = (
                        jp[(j, p)] >= K or
                        js[(j, s)] >= K or
                        ps[(p, s)] >= K
                    )
                    if not oops:
                        result.append((1 + j, 1 + p, 1 + s))
                        jp[(j, p)]+= 1
                        js[(j, s)]+= 1
                        ps[(p, s)]+= 1
        if len(result) > len(result0):
            result0 = result
    return result0


if __name__ == '__main__':
    sys.stdin.readline()
    casenum = 0
    for line in sys.stdin:
        casenum+= 1
        J, P, S, K = map(int, line.split())
        answer = solve(J, P, S, K)
        print "Case #%d: " % casenum, len(answer)
        for outfit in answer:
            print " ".join(map(str, outfit))
