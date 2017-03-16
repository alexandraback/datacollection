#!/usr/bin/python3

import sys

def solve_easy(a, b, k):
    cnt = 0
    for i in range(a):
        for j in range(b):
            if (i & j) < k:
                cnt += 1
    return cnt

t = int(sys.stdin.readline())
for i in range(1, t+1):
    a, b, k = map(int, sys.stdin.readline().strip().split())
    print("Case #%d:" % i, solve_easy(a, b, k))
