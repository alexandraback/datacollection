#!/usr/bin/env python
import sys
import random
def solve(set):
    C = set[0]
    F = set[1]
    X = set[2]

    time = 0
    cookiePsec = 2

    curr_wait = X/cookiePsec
    while True:
        next_wait = X/(cookiePsec+F)
        factory = C/cookiePsec+next_wait
        
        if factory < curr_wait:
            time += C/cookiePsec
            cookiePsec += F
            curr_wait = next_wait
        else:
            time += X/cookiePsec
            break

    return "%.8f" % time

numcase = int(sys.stdin.readline())
for casenum in range(1,numcase+1):
    set = map(float,sys.stdin.readline().strip().split())
    print 'Case #' + repr(casenum)+': '+solve(set)

