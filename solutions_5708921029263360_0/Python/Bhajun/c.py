#!/usr/bin/env python

from __future__ import division, print_function
import collections, itertools, sys


def f(J, P, S, K):
    combinations = list(itertools.product(range(1, J + 1), range(1, P + 1), range(1, S + 1)))
    filtered = 0
    
    JP, PS, JS = collections.defaultdict(int), collections.defaultdict(int), collections.defaultdict(int)
    
    for j, p, s in combinations:
        if JP[(j, p)] < K and PS[(p, s)] < K and JS[(j, s)] < K:
            JP[(j, p)] += 1
            PS[(p, s)] += 1
            JS[(j, s)] += 1
            filtered += 1
    
    return filtered


if __name__ == '__main__':
    T = int(sys.stdin.readline())
    
    for i in range(T):
        J, P, S, K = list(map(int, sys.stdin.readline().split()))
        
        print('Case #%d: %d' % (i + 1, f(J, P, S, K)))