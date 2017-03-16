#!/usr/bin/python

from __future__ import division

from scipy.special import polygamma, digamma

def solve(C, F, X):
    def timeToWithWithFactories(n):
        return X / (2 + F * n) + C * (digamma(2 / F + n) - digamma(2 / F)) / F

    def dt(n):
        return (C * polygamma(1, (2 / F) + n) / F) - ((F * X) / ((2 + F * n) ** 2))

    low = 0
    high = 1
    while dt(high) < 0:
        low = high
        high = high * 2

    while high - low > 1:
        mid = low + (high - low) // 2
        if dt(mid) < 0:
            low = mid
        else:
            high = mid

    candidates = range(max(0, low - 2), high + 3)
    return min(map(timeToWithWithFactories, candidates))

#print solve(500, 4, 2000)
#__import__('sys').exit(0)

T = int(raw_input())
for i in range(T):
    print "Case #%i: %.10f" % (i+1, solve(*(float(s) for s in raw_input().split())))
