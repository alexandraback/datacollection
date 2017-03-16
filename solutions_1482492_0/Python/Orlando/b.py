#!/usr/bin/env python

from math import sqrt

t = int(raw_input())

def avt2v(a, v0, t):
    return v0 + a * t

def avt2s(a, v0, t):
    return v0*t + 0.5 * a * t**2

def avs2t(a, v0, s):
    return 2*s / (sqrt(v0**2 + 2*a*s) + v0)

for tc in xrange(1, t+1):
    d, n, a = raw_input().split()
    d = float(d)
    n = int(n)
    a = int(a)
    ts = []
    xs = []
    for _ in xrange(n):
        t, x = map(float, raw_input().split())
        ts.append(t)
        xs.append(x)
    accs = map(float, raw_input().split())
    print "Case #%d:" % (tc,)
    for a in accs:
        v = 0
        tot = 0
        for i in xrange(1, len(ts)):
            me = tot + avt2s(a, v, ts[i]-ts[i-1])
            other = xs[i]
            if d <= other:
                od = d - xs[i-1]
                ov = (xs[i]-xs[i-1]) / (ts[i]-ts[i-1])
                ot = od / ov
                md = d - tot
                mt = avs2t(a, v, md)
                if d <= me:
                    if mt < ot:
                        print ot
                    else:
                        print mt
                else:
                    print ts[i-1] + avs2t(a, v, md)
                break
            if me > other:
                v = (xs[i]-xs[i-1]) / (ts[i]-ts[i-1])
                tot = other
            else:
                tot = me
                v = avt2v(a, v, (ts[i]-ts[i-1]))
