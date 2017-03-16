#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

def f(a, m):
    i = 0
    for e in m:
        if e >= a:
            break
        a += e
        i += 1

    if i > len(m) - 1:
        return 0

    x = f(a + a - 1, m[i:]) if a > 1 else 296024318791827391263971263
    y = f(a, m[i:-1])

    return min(x, y) + 1

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        a, _ = map(int, input().split())
        m = list(map(int, input().split()))
        m.sort()
        r = f(a, m)
        print('Case #{}: {}'.format(i+1, r))
