#!/usr/bin/env python
import itertools
class END(Exception):
    pass

def solve(A,B,K):
    count = 0
    for i in range(A):
        for j in range(B):
            if i & j < K: count += 1
    return count

T = int(input())
for i in range(T):
    A,B,K = [int(j) for j in raw_input().split()]

    result = solve(A,B,K)

    print 'Case #%d:' % (i+1), result
