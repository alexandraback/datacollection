#!/usr/bin/env python

def solve(C, F, X):
    t = 0.
    n = 0
    if X < C:
        return X / 2.
    t = C / 2.
    while True:
        twob = (X - C) / (2. + F * n)
        twb = X / (2. + F * (n + 1))
        if twob < twb:
            return t + twob
        n += 1
        t += C / (2. + F*n)

T = int(raw_input().strip())
for t in range(T):
    C, F, X = [float(i) for i in raw_input().strip().split()]
    print 'Case #%d: %f' % (t+1, solve(C, F, X))
