__author__ = 'bszikszai'

from io import *
import math

def simulate(r, c, w):
    guesses = int(math.floor(c/float(w)))
    isDivable = 0 if c % w == 0 else 1
    return guesses *(r-1) + (guesses - 1) + w + isDivable

def solve(f):
    inp = [int(x) for x in f.readline().rstrip('\n').rstrip('\r').split(' ')]
    return simulate(inp[0], inp[1], inp[2])

with open('input.txt', 'r') as f:
    with open('output.txt', 'wb') as g:
        cases = int(f.readline())
        for i in range(0, cases):
            solution = solve(f)
            print "Case #%s: %s" % (i+1, solution)
            g.write("Case #%s: %s\n" % (i+1, solution))