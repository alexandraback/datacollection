#!/usr/bin/python

import sys

def emit(text, *args):
    msg = text % args
    sys.stderr.write(msg)
    sys.stdout.write(msg)

def getline():
    return sys.stdin.readline().rstrip('\n')

conns = {} # global to avoid passing it around everywhere

# Gets to-be-visited zips and currently open return flights
# (last taken is at 0)
def result(city, zipset, flights):
    if not zipset:
        return city

    reachable = [ (z, 0) for z in conns[city] if z in zipset ]
    for f in range(len(flights)):
        reachable += [ (z, f+1) for z in conns[flights[f]]
                       if z in zipset ]
    reachable.sort()
    for z, f in reachable:
        returnflight = city if f == 0 else flights[f-1]
        r = result(z, zipset - set([z]), [returnflight] + flights[f:])
        if r:
            return city + r
    return None

def solve(zips, conns):
    # pick starting city
    for i in range(len(zips)):
        r = result(zips[i], set(zips[:i] + zips[i+1:]), [])
        if r:
            return r
    return "Error"  # not supposed to be possible

ncases = int(getline())

for casenr in range(1, ncases+1):
    n, m = [ int(s) for s in getline().split() ]
    zips = [ getline() for i in range(n) ]
    conns = {}
    for z in zips:
        conns[z] = []
    for i in range(m):
        c1, c2 = [ int(s) for s in getline().split() ]
        conns[zips[c1 - 1]].append(zips[c2 - 1])
        conns[zips[c2 - 1]].append(zips[c1 - 1])
    for z in zips:
        conns[z].sort()
    zips.sort()
    emit("Case #%d: %s\n", casenr, solve(zips, conns))
