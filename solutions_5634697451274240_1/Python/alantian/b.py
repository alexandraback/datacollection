#!/usr/bin/env python3

cache = dict()

def flip(s):
    return ''.join(['-' if _ == '+' else '+' for _ in s])

def f(s):
    if s in cache:
        return cache[s]

    if len(s) == 0:
        return 0

    n = len(s)
    res = n * 2
    for i in range(n + 1):
        prefix = s[:i]
        suffix = s[i:]
        if len(suffix) > 0 and set(suffix) != set(['+']):
            continue

        new_s = flip(prefix) + suffix

        for j in range(n):
            if set(new_s[j:]) == set(['+']):
                res = min(res, f(new_s[:j]) + int(i > 0))
                break

    cache[s] = res
    return res

T = int(input())
for case in range(1, T+1):
    s = input()
    print('Case #%d: %d' % (case, f(s)))

