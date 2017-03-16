#!/usr/bin/python

import sys

def farmcost(c, f, g):
    return sum([c/(2.+i*f) for i in range(g)])

def xcost(x, f, g):
    return x/(2.+f*g)

def thing(c, f, x, g):
    return f*x - c*(f*g+f+2)

def findfarms(c, f, x):
    minn = 0
    maxx = int(x+1)
    while minn < maxx:
        guess = (minn+maxx)/2
        t = thing(c, f, x, guess)
        if t > 0:
            minn = guess + 1
        elif thing(c, f, x, guess - 1) < 0:
            maxx = guess - 1
        else:
            return guess
    return minn
        

cases = int(sys.stdin.readline())

for casenum in range(1, cases+1):
    c,f,x = [float(x) for x in sys.stdin.readline().split()]
    g = findfarms(c, f, x)
    fc = farmcost(c, f, g) + xcost(x, f, g)
    print 'Case #{}: {}'.format(casenum, fc)
    #for g in range(100):
        #print farmcost(c, f, g) + xcost(x, f, g),
        #print thing(c, f, x, g)
