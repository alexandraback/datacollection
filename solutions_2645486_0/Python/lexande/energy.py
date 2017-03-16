#!/usr/bin/env python
import sys


def bestcase(maxe, recharge, vlist):
    vdict = dict(zip(range(0, len(vlist)), vlist))
    sortedkeys = sorted(vdict, key = vdict.get)[::-1]
    plan = [0] * len(vlist)
    for i in sortedkeys:
        plan[i] = energyat(maxe, recharge, plan, i)
    return sum(map(lambda (x,y): x*y, zip(plan, vlist)))

def energyat(maxe, recharge, planlist, index):
    e = maxe
    for i in range(0,index):
        e = min(maxe, recharge + e - planlist[i])
    futuree = e
    wasted = 0
    for i in range(index,len(planlist)):
        futuree = futuree - planlist[i]
        if futuree + wasted < e:
            e = futuree + wasted
        futuree += recharge
        if futuree > maxe:
            wasted += futuree - maxe
            futuree = maxe
    return e
      
T = int(sys.stdin.readline())
for case in range(0,T):
    (E, R, N) = sys.stdin.readline().split(" ")
    vlist = map(int, sys.stdin.readline().split(" "))
    print "Case #%i: %i" % (case + 1, bestcase(int(E), int(R), vlist))
