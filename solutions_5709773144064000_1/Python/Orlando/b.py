#!/usr/bin/env python

t = int(raw_input())

def simple(cookies, rate, target):
    return (target - cookies) / rate

for caseno in xrange(1, t+1):
    c, f, x = map(float, raw_input().split())
    t0 = 0.0
    c0 = 0.0
    rate = 2.0
    while True:
        tnofarm = t0 + simple(c0, rate, x)
        tfarm = t0 + simple(c0, rate, c0+c) + simple(0.0, rate+f, x)
        if tnofarm <= tfarm:
            print "Case #%d: %.7f" % (caseno, tnofarm)
            break
        else:
            t0 += simple(c0, rate, c0+c)
            rate += f
            c0 = 0.0
