#!/usr/bin/env python3

import sys

T = int(sys.stdin.readline())
for i in range(T):
    tokens = sys.stdin.readline().split()
    K = int(tokens[0])
    C = int(tokens[1])
    S = int(tokens[2])
    L = max(1 + K - C, 1)
    if S < L:
        P = None
    else:
        base = 0
        for j in range(K - L):
            base += j * K**(C - j - 1)
        P = [base + x + 1 for x in range(K - L, K)]
    sys.stdout.write('Case #{}: {}\n'.format(i + 1, 'IMPOSSIBLE' if P is None else ' '.join(str(p) for p in P)))
