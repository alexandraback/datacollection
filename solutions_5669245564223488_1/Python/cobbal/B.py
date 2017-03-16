#!/usr/bin/python

from itertools import permutations
from collections import defaultdict

import re
import math

M = 1000000007

def solve(N):
    cars = raw_input().split()
    cars2 = []

    for ci in range(len(cars)):
        car = cars[ci]
        begin = car[0]
        end = car[-1]

        x = re.sub('^' + begin + '+', '', car)
        x = re.sub(end + '+$', '', x)

        for cj in range(len(cars)):
            if ci != cj and (set(x) & set(cars[cj])):
                return 0

        y = car
        for c in range(ord('a'), ord('z') + 1):
            y = re.sub(chr(c) + '+', '', y, 1)
        if y:
            return 0

        cars2.append((begin, end))

    nops = defaultdict(int)
    ops = {}
    rops = {}
    for c in cars2:
        if c[0] == c[1]:
            nops[c[0]] += 1
        else:
            if c[0] in ops:
                return 0
            ops[c[0]] = c[1]
            if c[1] in rops:
                return 0
            rops[c[1]] = c[0]

    del rops

    possibs = 1
    while True:

        #print '------', possibs
        #print nops
        #print ops

        for a, b in ops.items():
            if a == b:
                return 0
            possibs *= math.factorial(nops[a])
            del nops[a]
            possibs *= math.factorial(nops[b])
            del nops[b]
            if b in ops:
                ops[a] = ops[b]
                del ops[b]
                break
        else:
            break

    for x in nops.values():
        possibs *= math.factorial(x)

    possibs *= math.factorial(len(nops) + len(ops))

    return possibs % M



T = int(raw_input())
for i in range(T):
    print "Case #%i: %s" % (i+1, solve(*(int(s) for s in raw_input().split(' '))))
