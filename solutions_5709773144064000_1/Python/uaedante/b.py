#!/usr/bin/python
import os, sys

fn = sys.stdin

total = int(fn.readline())

for case in range(1, total + 1):
    x = fn.readline().split()
    for i in range(0, 3):
        x[i] = eval(x[i])
    s = float(x[2])
    t = 2.0
    c = float(x[0])
    f = float(x[1])
    time = 0
    while True:
        if s < c:
            time += s / t
            break
        time += c / t
        s -= c
        if c * t < s * f:
            s += c
            t += f
        else:
            time += s / t
            break
    print "Case #%d: %0.7f" % (case, time)
