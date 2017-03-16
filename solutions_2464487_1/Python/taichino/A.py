# -*- coding: utf-8 -*-

import sys

MAX = 2 * pow(10, 18)
N = int(sys.stdin.readline())

for n in range(1, N+1):
    r, t = map(int, sys.stdin.readline().split())

    minimum = 1
    maximum = MAX

    ans = 1
    cur = int((minimum + maximum) / 2)
    while True:
        paint = 2 * cur * (cur + 1) + (2 * r - 3) * cur
        if maximum - minimum <= 1:
            tmp = 2 * maximum * (maximum + 1) + (2 * r - 3) * maximum
            if tmp <= t:
                ans = maximum
            else:
                ans = cur
            break

        if paint > t:
            maximum = cur - 1
        elif paint <= t:
            minimum = cur
        cur = int((minimum + maximum) / 2)
    
    print 'Case #%(n)s: %(ans)s' % locals()
