#!/usr/bin/python

import sys

def solve_truth(naomi, ken):
    naomi = sorted(naomi)
    ken = sorted(ken)
    for n in naomi:
        if n > ken[-1]:
            return len(ken)
        for i in range(len(ken)):
            if ken[i] > n:
                ken = ken[:i] + ken[i+1:]
                break
    return 0

def solve_lie(naomi, ken):
    naomi = sorted(naomi)
    ken = sorted(ken)
    points = 0
    for n in naomi:
        if n > ken[-1]:
            return points + len(ken)
        if n > ken[0]:
            ken = ken[1:]
            points += 1
        else:
            ken = ken[:-1]
    return points

def emit(text, *args):
    msg = text % args
    sys.stderr.write(msg)
    sys.stdout.write(msg)

def getline():
    return sys.stdin.readline().rstrip('\n')

ncases = int(getline())

for casenr in range(1, ncases+1):
    n = int(getline())
    naomi = [ float(s) for s in getline().split() ]
    ken = [ float(s) for s in getline().split() ]
    emit("Case #%d: %d %d\n", casenr, solve_lie(naomi, ken), solve_truth(naomi, ken))
