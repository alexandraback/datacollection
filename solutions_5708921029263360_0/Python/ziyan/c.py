#!/usr/bin/env python

import os
import sys
import collections

def solve(J, P, S, K):
    sols = []
    jppairs = collections.defaultdict(int)
    pspairs = collections.defaultdict(int)
    jspairs = collections.defaultdict(int)
    for j in range(J):
        for p in range(P):
            for s in range(S):
                if jppairs[(j, p)] < K and pspairs[(p, s)] < K and jspairs[(j, s)] < K:
                    sols += [(j, p, s)]
                    jppairs[(j, p)] += 1
                    pspairs[(p, s)] += 1
                    jspairs[(j, s)] += 1
    return sols

def main():
    T = int(sys.stdin.readline().strip())
    for t in range(T):
        J, P, S, K = map(int, sys.stdin.readline().strip().split())
        sols = solve(J, P, S, K)
        print 'Case #%d: %d' % (t + 1, len(sols))
        for sol in sols:
            print '%d %d %d' % (sol[0] + 1, sol[1] + 1, sol[2] + 1)

if __name__ == '__main__':
    main()

