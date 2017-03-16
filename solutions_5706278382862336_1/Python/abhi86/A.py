#!/usr/bin/env python

import fractions
import math

if __name__ == '__main__':
    T = int(raw_input())
    for i in range(1, T + 1):
        P, Q = map(int, raw_input().split('/'))
        g = fractions.gcd(P, Q)
        P /= g
        Q /= g
        ans = 0
        if Q != 0 and (Q & (Q - 1) == 0):
            if P == 1:
                ans = int(math.log(Q, 2))
            else:
                while Q > P:
                    Q /= 2
                    ans += 1
        else:
            ans = 'impossible'
        print 'Case #%d: %s' % (i, ans) 
