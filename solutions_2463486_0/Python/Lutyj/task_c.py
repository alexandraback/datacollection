#!/usr/bin/python

import sys
from bisect import bisect

def check(cur):
    L = len(cur)

    for i in range(L):
        s = 0
        for j in range(i+1):
            s += cur[j] * cur[i-j]

        if (s > 9): return False

    return True

def simple(L, pc, cur, res):
    if (L-pc-1 < pc):
        res.append(int(''.join(str(d) for d in cur)))
        return

    start = 1 if pc == 0 else 0

    for d in range(start, 3):
        cur[pc] = d
        cur[L-pc-1] = d

        if check(cur):
            simple(L, pc+1, cur, res)

        cur[pc] = 0
        cur[L-pc-1] = 0

res = [0, 3]

for L in range(1, 51):
    cur = [0] * L
    simple(L, 0, cur, res)

res.sort()
res = [x**2 for x in res]

T = int(sys.stdin.readline())
for t in range(T):
    nums = sys.stdin.readline().split()
    A, B = int(nums[0]), int(nums[1])

    print('Case #{0}:'.format(t+1), bisect(res, B) - bisect(res, A-1))
