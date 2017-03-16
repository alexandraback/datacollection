#!/usr/bin/env python
import sys

l = 0
c = 0
e = 0
r = 0
n = 0
v = []
max_gain = 0

def calc():
    global e, r, n, v
    global max_gain

    def find(s):
        global max_gain

        if len(s[0]) > 0 and s[1] >= 0:
            a = s[0][0]
            nv = s[0][1:]
            for i in range(0, s[1] + 1):
                ng = s[2] + a * i
                if ng > max_gain:
                    max_gain = ng
                if len(nv) > 0:
                    ne = s[1] - i + r
                    if ne > e:
                        ne = e
                    new_state = (nv, ne, ng)
                    find(new_state)
    
    initial_state = (v, e, 0)
    find(initial_state)
    return max_gain

def process(line):
    global l
    global c
    global t
    global e
    global r
    global n
    global v
    global max_gain

    l += 1;

    if l == 1:
        c = 1
    else:
        if e == 0:
            (e, r, n) = [ int(d) for d in line.split() ]
        else:
            v = [ int(d) for d in line.split() ]
            result = calc()
            print "Case #{}: {}".format(c, result)
            c += 1
            e = 0
            max_gain = 0


if len(sys.argv) < 2:
    print "Please supply the input file as argument"
    sys.exit(2)

filename = sys.argv[1]
with open(filename) as f:
    for line in f:
        if len(line.strip()):
            process(line.strip())

