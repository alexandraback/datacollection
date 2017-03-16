#!/usr/bin/env python3

def f(n):
    if n == 0:
        return -1
    seen = set()

    i = 1
    while True:
        v = n * i
        digits = set(str(v))
        seen = seen | digits

        if len(seen) == 10:
            return v

        i += 1

T = int(input())
for case in range(1, T + 1):
    n = int(input())
    res = f(n)
    print('Case #%d: %s' % (case, 'INSOMNIA' if res == -1 else str(res)))
