#!/usr/bin/python

import sys

def solve(cost, prod, goal):
    rate = 2.0
    elapsed = 0.0

    while goal / (rate + prod) + cost / rate < goal / rate:
        elapsed += cost / rate
        rate += prod

    return elapsed + (goal / rate)

def emit(text, *args):
    msg = text % args
    sys.stderr.write(msg)
    sys.stdout.write(msg)

def getline():
    return sys.stdin.readline().rstrip('\n')

ncases = int(getline())

for casenr in range(1, ncases+1):
    arr = [ float(s) for s in getline().split() ]
    emit("Case #%d: %s\n", casenr, solve(*arr))
