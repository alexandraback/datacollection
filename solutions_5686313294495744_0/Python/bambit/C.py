#!/usr/local/bin/python

import itertools
import sys

def possible_fakes(fake_ids, real_ids, topics):
    sfirsts = set(topics[rid][0] for rid in real_ids)
    ssecs = set(topics[rid][1] for rid in real_ids)

    rfirsts = set(topics[rid][0] for rid in fake_ids)
    rsecs = set(topics[rid][1] for rid in fake_ids)

    return rfirsts.issubset(sfirsts) and rsecs.issubset(ssecs)

def solve(t):
    N = int(sys.stdin.readline().rstrip())
    topics = {}
    for i in range(N):
        topics[i] = sys.stdin.readline().rstrip().split()

    max_possible = N-1
    while max_possible > 0:
        for comb in itertools.combinations(range(N), max_possible):
            if possible_fakes(set(comb), set(range(N))-set(comb), topics):
                print 'Case #{}: {}'.format(t, max_possible)
                return
        max_possible -= 1

    print 'Case #{}: {}'.format(t, 0)

if __name__=="__main__":
    T = int(sys.stdin.readline())
    for i in range(1, T+1):
        solve(i)
