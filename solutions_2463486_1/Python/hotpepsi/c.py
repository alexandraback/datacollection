#!/usr/bin/env python

import sys

def is_palindrome(n):
    s = str(n)
    return s == s[::-1]

def pali1(n):
    s = str(n)
    return s + s[-2::-1]

def pali2(n):
    s = str(n)
    return s + s[::-1]

a = [x*x for x in [int(pali1(y)) for y in range(1, 10**6)] if is_palindrome(x*x)]
b = [x*x for x in [int(pali2(y)) for y in range(1, 10**6)] if is_palindrome(x*x)]
pali_sq = sorted(a + b)

def p(n):
    c = 0
    for x in pali_sq:
        if x > n:
            break
        c += 1
    return c

n = int(sys.stdin.readline())
for t in range(1, n+1):
    x = sys.stdin.readline().split(" ")
    ans = str(p(int(x[1])) - p(int(x[0])-1))
    print("Case #" + str(t) + ": " + ans)

