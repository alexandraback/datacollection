#!/usr/bin/env python

from __future__ import print_function
from sys import argv,stdin

def max_score(mine_sorted_iter,other_sorted_iter):
    score = 0
    for y in other_sorted_iter:
        try:
            x=mine_sorted_iter.next()
        except StopIteration:
            return score
        while  x<y:
            try:
                x=mine_sorted_iter.next()
            except StopIteration:
                return score
        score += 1
    return score

with open(argv[1]) if len(argv)>1 else stdin as f:
    T = int(f.readline())
    for i in xrange(T):
        A, B, K = map(int,f.readline().split())
        s=0
        for a in xrange(A):
            for b in xrange(B):
                if a & b < K:
                    s+=1
        print('Case #%d: %d'%(i+1,s))
