#!/usr/bin/env python2.6

import sys

# get number of cases
num = int(sys.stdin.readline())

# read cases data
cases = sys.stdin.readlines()

# process cases
for j in xrange(len(cases)):
    case = [int(v) for v in cases[j].split(' ')]
    
    # to simplify - give names
    googlers = case[0]
    surprises = case[1]
    best = case[2]
    results = case[3:]
    max = 0
    
    # calcualte qualification values
    q_real = best + 2*(best-1)
    q_surprise = q_real - 2
    
    if q_surprise < best: q_surprise = best
    
    # check each googler
    for result in results:
        if result >= q_real:
            max += 1
            continue
        if surprises and result >= q_surprise:
            max += 1
            surprises -= 1

    print "Case #%d: %d" % (j+1, max)