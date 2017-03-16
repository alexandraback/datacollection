#!/usr/bin/python2 -u
# -*- coding: utf-8 -*-
#
import sys, math, re

### ----- Variables
LINES = []

### ----- Functions
def pop_line():
    global LINES
    if len(LINES) == 0:
        return None
    line = LINES[0]
    LINES = LINES[1:]
    return line

def check_if_valid(connected):
    alphabets = {}
    curr = connected[0]
    for c in connected:
        if curr != c:
            if alphabets.has_key(c):
                return 0
            curr = c
        alphabets[c] = 1
    return 1

def check_if_valid_2(connected):
    alphabets = {}
    while True:
        curr = connected[0]
        if alphabets.has_key(curr):
            return 0
        alphabets[curr] = 1

        old = connected
        connected = re.sub('^%s+' % curr, '', connected)
        if old == connected or len(connected) == 0:
            break

    return 1 if len(connected)==0 else 0

def connect_trains(trains, connected):
    #print trains, connected
    if len(trains) == 0:
        return 1
        return check_if_valid_2(connected)

    possible = 0
    for i in xrange(len(trains)):
        t = trains[i]
        """
        if len(connected)==0 or connected[-1] == t[0]:
            possible += connect_trains(trains[:i] + trains[i+1:], connected+t)
        """
        #possible += connect_trains(trains[:i] + trains[i+1:], connected+t)

        possible += connect_trains(trains[:i] + trains[i+1:], connected+t)

    return possible

def check_connectibility(alpha, tprev, tnext):
    for k in alpha.keys():
        if k in tnext:
            if tprev[-1] != tnext[0]:
                return False
    return True

def reduce_connected(connected):
    connew = connected[0]
    for c in connected[1:]:
        if c != connew[-1]:
            if c in connew:
                return None
            connew += c
    return connew

def connect_trains_2(trains, connected):
    #print trains, connected
    if len(trains) == 0:
        return 1

    possible = 0
    for i in xrange(len(trains)):
        t = trains[i]

        if (connected != '') and (connected[-1] in t) and (not t[0] == connected[-1]):
            continue

        connew = reduce_connected(connected + t)
        if connew == None:
            continue

        possible += connect_trains_2(trains[:i] + trains[i+1:], connew)

    return possible

### ----- Program Main
LINES = [line.rstrip() for line in sys.stdin]

T = int(pop_line())
for t in range(T):

    N = int(pop_line())
    trains = pop_line().split()

    print 'Case #%d: %d' % (t+1, connect_trains_2(trains, ''))
