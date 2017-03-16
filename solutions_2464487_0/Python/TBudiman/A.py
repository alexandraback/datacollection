#!/usr/bin/env python
import sys

l = 0
c = 0

def calc(r, t):
    cr = 0
    while t > 0:
        t -= (2 * r) + ((cr + 1) ** 2) - (cr ** 2)
        if t >= 0:
            cr += 2
        
    return cr / 2

def process(line):
    global l
    global c
    global t

    l += 1;

    if l == 1:
        c = 1
    else:
        (r, t) = [ int(d) for d in line.split() ]
        result = calc(r, t)
        print "Case #{}: {}".format(c, result)
        c += 1
        board = []


if len(sys.argv) < 2:
    print "Please supply the input file as argument"
    sys.exit(2)

filename = sys.argv[1]
with open(filename) as f:
    for line in f:
        if len(line.strip()):
            process(line.strip())

