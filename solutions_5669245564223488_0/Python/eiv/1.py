#!/usr/bin/env python

import sys
from collections import defaultdict
from itertools import permutations

def Solve(N, cars):
    def check(train):
        train = "".join(train)
        seen = set()
        last = ''
        for t in train:
            if last != t:
                if t in seen: return False
                seen.add(t)
                last = t
        return True
    allcars = filter(check, permutations(cars))
    #print allcars
    return str(len(allcars))

inp = open(sys.argv[1], 'r').readlines()
T = int(inp[0].strip())
for t in range(T):
    N = int(inp[2*t+1].strip())
    cars = inp[2*t+2].strip().split()
    print "Case #"+str(t+1)+": "+Solve(N, cars)

    
