#!/usr/bin/python

import sys
from collections import deque


def solve(N):
    if N == 1:
        return 1
    Q = deque()
    Q.append(1)
    dist = {1: 1}

    while Q:
        k = Q.popleft()
        dk = dist[k] + 1
        kr = int(str(k)[::-1])
        for v in [k + 1, kr]:
            if v == N:
                return dk
            if not v in dist:
                dist[v] = dk
                Q.append(v) 
    
    return 0


if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        N = int(raw_input())
        answer = solve(N)
        print "Case #{0}:".format(1 + t), answer
