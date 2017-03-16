#!/usr/bin/python

import math

def recycle(n, digits, mask):
    nums = set()
    for i in range(digits - 1):
        n = (n % mask) * 10 + (n / mask)
        nums.add(n)
    return nums

T = int(raw_input())
for i in range(1, T+1):
    [A, B] = map(int, raw_input().split())
    digits = int(math.log10(A)) + 1
    mask   = 10 ** (digits - 1)
    result = 0
    for n in range(A, B+1):
        for m in recycle(n, digits, mask):
            if n < m and m <= B:
                result += 1
    print "Case #" + str(i) + ": " + str(result)

