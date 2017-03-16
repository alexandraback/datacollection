#!/usr/bin/python3
# -*- coding: utf-8 -*-
# †
def f(n):
    seen = [False] * 10
    for i in range(1, 100): # i <= 72
        s = str(n * i)
        for ch in s:
            seen[ord(ch) - ord('0')] = True
        if all(seen):
            return n * i
    return 'INSOMNIA'

t = int(input())
for case in range(t):
    n = int(input())
    res = f(n)
    print('Case #{}: {}'.format(case+1, res))
