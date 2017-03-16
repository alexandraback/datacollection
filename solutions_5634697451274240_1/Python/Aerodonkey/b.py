#!/usr/bin/env python3

import sys

T = int(sys.stdin.readline())
for i in range(T):
    S = sys.stdin.readline().strip()
    S += '+'
    L = len(S)
    y = 0
    while S != '+' * L:
        d = '+' if S[0] == '-' else '-'
        p = S.find(d)
        S = d * p + S[p:]
        y += 1
    sys.stdout.write('Case #{}: {}\n'.format(i + 1, y))
