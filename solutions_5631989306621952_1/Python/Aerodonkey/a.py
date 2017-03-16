#!/usr/bin/env python3

import sys

def solve(S):
    W = ['']
    for i in range(len(S)):
        y = None
        for j, c in enumerate(S[:i + 1]):
            w = c + W[j] + S[j + 1:i + 1]
            if y is None or w > y:
                y = w
        W.append(y)
    return W[-1]

T = int(sys.stdin.readline())
for i in range(T):
    S = sys.stdin.readline().strip()
    y = solve(S)
    sys.stdout.write('Case #{}: {}\n'.format(i + 1, y))
