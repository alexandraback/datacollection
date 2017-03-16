from __future__ import print_function

import sys

f = sys.stdin

count = int(f.readline())

def printAttack(a):
    print("day {1}, tribe {0} [{2}, {3}] @ {4}".format(*a), file=sys.stderr)
    #tribe, day, west, east, st
       
def printAttacks(l):
    for a in l:
        printAttack(a)

def succeeds(wall, west, east, st):
    currentH = 0
    wasIn = False
    for (x, h) in wall:
        if (not wasIn) and x > west:
            wasIn = True
        if x > west and currentH < st:
            return True
        if wasIn and x >= east:
            if currentH >= st:
                return False
            else:
                return True
        currentH = h

def improve(wall, west, east, st):
    currentH = 0
    wasIn = False
    i = 0
    while i < len(wall):
        (x, h) = wall[i]

        print("Start {}: {}".format(i, wall), file=sys.stderr)

        if (not wasIn) and x > west:
            wasIn = True
        if (x > west and currentH < st): # or (wasIn and x >= east):
            # defect
            (px, ph) = wall[i-1]
            if px >= west: # change
                wall[i-1] = (px, st)
            else: # px < west:
                wall.insert(i, (west, st))
                i += 1
            
            # don't go eastward of the breach
            #if i+1 < len(wall):
            if x > east:
                wall.insert(i, (east, ph))

        print("End {}: {}".format(i, wall), file=sys.stderr)

        if x >= east:
            print("Return", file=sys.stderr)
            return

        i += 1

        currentH = h



for index in range(1, count+1):
    print("##### {} #####".format(index), file=sys.stderr)

    N = int(f.readline())
    attacks = []
    wall = [(-10**20, 0), (10**20, 0)]

    for tribe in range(N):
        [day, n, west, east, st, deltaDay, deltaDist, deltaS] = map(int, f.readline().split())

        for att in range(n):
            attacks.append((tribe, day, west, east, st))
            day += deltaDay
            st += deltaS
            west += deltaDist
            east += deltaDist
            printAttack(attacks[-1])

    attacks.sort(key=lambda a: a[1])

    prevDay = -1
    improvements = []
    successes = 0
    for a in attacks:
        (tribe, day, west, east, st) = a
        if day != prevDay:
            print("Improvements: {}".format(improvements), file=sys.stderr)
            for i in improvements:
                improve(wall, *i)
                print("TW {}".format(wall), file=sys.stderr)
            improvements = []
        su = succeeds(wall, west, east, st)
        if su:
            improvements.append((west, east, st))
            successes += 1
        print("Wall: {}".format(wall), file=sys.stderr)
        printAttack(a)
        print("Succeeds? {}".format(su), file=sys.stderr)
        prevDay = day

    for i in improvements: improve(wall, *i)
    print("Final wall: {}".format(wall), file=sys.stderr)

    print("Case #{}: {}".format(index, successes))
