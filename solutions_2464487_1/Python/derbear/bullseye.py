#!/usr/bin/python

F_IN = "input"

from math import *

def cost(r, y):
    return y * (2*r - 3 + 2*(y+1))

def cost_inverse(r, t):
    i = 1
    increment = (t / 2)+1
    while cost(r, i) < t:
        while cost(r, i) < t:
            i += increment
        i -= increment
        increment /= 2
        increment += 1
        if increment <= 2:
            break
    while cost(r, i) <= t:
        i += 1
    return i-1

with open(F_IN, 'r') as f:
    nlines = int(f.readline())
    i = 0
    while i < nlines:
        i += 1
        line = f.readline()
        stuff = line.split(' ')
        r = int(stuff[0])
        t = int(stuff[1])
        print "Case #{}: {}".format(i, cost_inverse(r, t))
