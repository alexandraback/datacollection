import math, sys, os
f = open('A-large.in')
T = int(f.readline())

s = ''
for cas in range(1, T+1):
    r, t = map(int, f.readline().split())
    r = r*2 - 1
    L, R, ans = 1, t, 1
    while (L <= R):
        mid = (L + R) >> 1
        if (2*mid*mid+r*mid <= t):
            ans = mid
            L = mid + 1
        else: R = mid - 1
    s += 'Case #' + str(cas) + ': ' + str(ans) + '\n'

open('out.txt', 'w').write(s)
