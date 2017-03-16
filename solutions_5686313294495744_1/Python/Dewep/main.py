#!/usr/bin/env python3

#import itertools
from random import shuffle

def solve(w1, w2, N):
    #positions = itertools.permutations(range(N))
    pos = [i for i in range(N)]
    max_number = 0
    #for pos in positions:
    for i in range(1000):
        number = 0
        words1 = []
        words2 = []
        for i in pos:
            if words1.count(w1[pos[i]]) >= 1 and words2.count(w2[pos[i]]) >= 1:
                number += 1
            words1.append(w1[pos[i]])
            words2.append(w2[pos[i]])
        max_number = max(max_number, number)
        shuffle(pos)
    return max_number

T = int(input())

for t in range(T):
    N = int(input())
    words1 = list()
    words2 = list()
    for n in range(N):
        w1, w2 = input().split()
        words1.append(w1)
        words2.append(w2)
    number = solve(words1, words2, N)
    print("Case #%d: %d" % (t + 1, number))
