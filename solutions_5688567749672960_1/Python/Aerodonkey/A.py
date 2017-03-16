#!/usr/bin/env python3

import sys

def get_steps(n):
    if n < 10:
        return n
    s = str(n)
    m = len(s)
    h = m // 2
    l = m - h
    if s[:h] == '1' + '0' * (h - 1):
        p = int('9' * (m - 1))
        return get_steps(p) + (n - p)
    else:
        if s[m - l:] == '0' * l:
            q = str(int(s[:h]) - 1)
            t = q + '0' * (l - 1) + '1'
            if q == '1' + '0' * (h - 1):
                d = 0
            else:
                d = 1
        else:
            t = s[:h] + '0' * (l - 1) + '1'
            d = 1
        p = int(t[::-1])
        return get_steps(p) + d + (n - int(t))

t = int(sys.stdin.readline())
for i in range(t):
    n = int(sys.stdin.readline())
    sys.stdout.write('Case #{}: {}\n'.format(i + 1, get_steps(n)))
