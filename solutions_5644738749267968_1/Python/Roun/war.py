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
    num_cases = int(f.readline())
    for i in xrange(num_cases):
        N = int(f.readline())
        Naomi_blocks = sorted([float(x) for x in f.readline().split()])
        Ken_blocks = sorted([float(x) for x in f.readline().split()])
        Naomi_score_deceitful = max_score(iter(Naomi_blocks),iter(Ken_blocks))
        Naomi_score_war = N - max_score(iter(Ken_blocks),iter(Naomi_blocks))
        print('Case #%d: %d %d'%(i+1,Naomi_score_deceitful,Naomi_score_war))
