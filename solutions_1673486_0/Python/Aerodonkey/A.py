#!/usr/bin/env python
# Wentao Han (wentao.han@gmail.com)

import sys

T = int(sys.stdin.readline().strip())
for x in range(1, T + 1):
    A, B = (int(t) for t in sys.stdin.readline().split())
    P = [float(t) for t in sys.stdin.readline().split()]
    q = 1.0
    y = float(min(A + B + 1, 1 + B + 1))
    for i, p in enumerate(P):
        q *= p
        y = min(y, q * ((A - i - 1) + (B - i - 1) + 1) + (1 - q) * ((A - i - 1) + (B - i - 1) + 1 + B + 1))
    sys.stdout.write('Case #%d: %0.6f\n' % (x, y))
