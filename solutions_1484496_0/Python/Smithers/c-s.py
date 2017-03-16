#!/usr/bin/env python

for c in xrange(1, int(raw_input())+1):
    values = [int(x) for x in raw_input().split()]
    n = values[0]
    values = values[1:]
    sel = [0 for x in xrange(n)]
    
    test = 0
    while True:
        for i in xrange(n):
            if sel[i] == 0:
                sel[i] = 1
                test += values[i]
                break
            elif sel[i] == 1:
                sel[i] = 2
                test -= 2 * values[i]
                break
            elif sel[i] == 2:
                sel[i] = 0
                test += values[i]
        if test == 0:
            print "Case #" + str(c) + ":"
            for i in xrange(n):
                if sel[i] == 1: print values[i],
            print
            for i in xrange(n):
                if sel[i] == 2: print values[i],
            print
            break
