import sys
from itertools import *
from collections import defaultdict

def ilen(seq): return sum(imap(lambda x:1, seq))

def solve(D, depth=0):
    tallest = max(D)
    count = D.pop(tallest)
    if tallest < 4: return tallest 

    # take [count] turns to split all the tallest stacks
    D[tallest/2] += count
    D[tallest-tallest/2] += count
    oscore = count + solve(D, depth+1)
    return min(oscore, tallest)

N = raw_input()
for n in range(1, int(N) + 1):
    raw_input()
    D = map(int, raw_input().split())
    D = defaultdict(int, ((k,ilen(g)) for k, g in groupby(D, lambda x:x)))
    print "Case #%d: %d" % (n, solve(D))
