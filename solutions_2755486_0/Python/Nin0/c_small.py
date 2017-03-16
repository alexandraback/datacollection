#!/usr/bin/python3

import sys
import collections

T = int(sys.stdin.readline())
caseNum = 0

def repair(left, right, strength):
    global zid
    for i in range(left, right):
        zid[i] = max(zid[i], strength)

def success(left, right, strength):
    for i in range(left, right):
        if zid[i] < strength:
            return 1
    return 0
        
def solve(tribe_data):
    # print(tribe_data)
    global zid
    zid = [0 for i in range(-500, 500+1)]
    events = [] # list of events
    for d, n, w, e, s, dd, dp, ds in tribe_data:
        for i in range(n):
            events.append( (d + i*dd, w+i*dp, e+i*dp, s+i*ds, "attack") )
            events.append( (d + i*dd + 0.5, w+i*dp, e+i*dp, s+i*ds, "repair") )
    events.sort()
    succ = 0
    for time, left, right, strength, mode in events:
        if mode == 'repair':
            repair(left, right, strength)
        else:
            # mode == 'attack'
            succ += success(left, right, strength)
    return succ

while caseNum < T:
    caseNum += 1
    N = int(sys.stdin.readline())
    tribe_data = []
    for i in range(N):
        tribe_data.append( tuple(map(int, sys.stdin.readline().strip().split(' '))) )
    print("Case #{0}: {1}".format(caseNum, solve(tribe_data)))
