#!/usr/bin/env python3
modulo = 1000000007
from fractions import gcd
from itertools import permutations


def answer():
    n = int(input())
    a = input().split()
    for i in range(n):
        t = ""
        for j in range(len(a[i])):
            if len(t) == 0 or t[-1] != a[i][j]:
                t += a[i][j]
        a[i] = t
    ans = 0
    for perm in permutations(a):
        s = "".join(perm)
        occur = {}
        good = True
        for i in range(len(s)):
            if s[i] in occur and occur[s[i]]!= i-1:
                good = False
                break
            occur[s[i]] = i
        if good:
            ans += 1
#    print(a)
    return ans

T = int(input())
for case in range(1, T+1):
    print("Case #{}: {}".format(case, answer()))
