#!/usr/bin/env python3

import sys
from collections import defaultdict

T = int(sys.stdin.readline())
for i in range(T):
    N = int(sys.stdin.readline())
    F = defaultdict(int)
    for j in range(2 * N - 1):
        tokens = sys.stdin.readline().split()
        for ns in tokens:
            n = int(ns)
            F[n] += 1
    M = []
    for n, f in F.items():
        if f % 2 == 1:
            M.append(n)
    M.sort()
    sys.stdout.write('Case #{}: {}\n'.format(i + 1, ' '.join(str(m) for m in M)))
