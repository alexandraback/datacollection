#!/usr/bin/env python3

import sys, os, re

def debug(x):
    print(x, file=sys.stderr) 

D = [int(x) for x in sys.stdin.readlines()]
N, D = D[0], D[1:]

debug(N)
debug(D)

for i, d in enumerate(D, 1):
    ans = ""
    if d == 0:
        ans = "INSOMNIA"
    else:
        seendigits = {}
        j = 0
        while(len(seendigits) < 10):
            j += 1
            d_run = d*j
            for x in str(d_run):
                seendigits[x] = 1
        ans = d_run 
    print("Case #%d: %s" % (i, str(ans)))
    
