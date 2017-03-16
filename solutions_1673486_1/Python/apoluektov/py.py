import sys
from math import *
from collections import *


def line():
    return sys.stdin.readline()


#bprobs = None

#def prob(nbksp, probs, a, b):
#    bprobs[nbksp] = probs[a-nbksp] * bprobs[nbksp-1]
#    return bprobs[]


def nstrokes(nbksp, a, b):
    return b - a + 2*nbksp + 1


def solve(a, b, probs):
    bprobs = [1.0 for i in range(a+1)]
    for i in range(a-1, -1, -1):
        bprobs[i] = bprobs[i+1] * probs[a-i-1]

    #print bprobs

    minstrokes = min(bprobs[i]*nstrokes(i, a, b) + (1 - bprobs[i])*(nstrokes(i,a,b) + b+1) for i in range(0, a+1))

    #print [bprobs[i]*nstrokes(i, a, b) + (1 - bprobs[i])*(nstrokes(i,a,b) + b+1) for i in range(0, a+1)]

    giveup = b + 2
    return round(min(minstrokes, giveup),7)


tc = int(line())
for i in range(1, tc+1):
    
    # read params
    a, b = [int(t) for t in line().split()]
    probs = [float(t) for t in line().split()]
      

    print "Case #%s: %s" % (i, solve(a,b,probs))
