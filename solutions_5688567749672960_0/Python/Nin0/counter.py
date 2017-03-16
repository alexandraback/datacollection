#!/usr/bin/python3

import sys
from collections import deque

MAX_N = 10**6

def flip(n):
    m = 0
    while n > 0:
        m *= 10
        m += n % 10
        n //= 10
    return m

neigh = [(i+1, flip(i)) for i in range(MAX_N+1)]
d = [None for i in range(MAX_N+1)]
parent = [None for i in range(MAX_N+1)]

d[0] = 0
q = deque([0])

while len(q) > 0:
    u = q.popleft()
    for sos in neigh[u]:
        if sos > MAX_N:
            continue
        if d[sos] is not None:
            continue
        d[sos] = d[u] + 1
        parent[sos] = u
        q.append(sos)
        
t = int(sys.stdin.readline())
for test_case_id in range(1, t+1):
    n = int(sys.stdin.readline())
    print('Case #{0}: {1}'.format(test_case_id, d[n]))
