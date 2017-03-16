#!/usr/bin/env python3

import sys

T = int(sys.stdin.readline())
for i in range(T):
    N = int(sys.stdin.readline())
    if N == 0:
        y = None
    else:
        S = set()
        y = N
        while True:
            S.update(str(y))
            if len(S) == 10:
                break
            y += N
    sys.stdout.write('Case #{}: {}\n'.format(i + 1, 'INSOMNIA' if y is None else y))
