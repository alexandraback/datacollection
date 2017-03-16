#! /usr/bin/env python

import sys

done = [True] * 10
for it in range(1, int(sys.stdin.readline()) + 1):
    seen = [False] * 10
    N = int(sys.stdin.readline())
    if not N:
        # zero is the only number which never generates all digits of 0-9
        print('Case #' + str(it) + ': INSOMNIA')
        continue
    i = 1
    while seen != done:  # too lazy for real bitsets
        for ch in str(i * N):
            seen[int(ch)] = True
        i += 1
    print('Case #' + str(it) + ': ' + str((i-1) * N))
