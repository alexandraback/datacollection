#!/usr/bin/env python

import sys
import math

glo_max = 0

def dynamic(e, r, tasks):
    if len(tasks) == 0:
        return 0
    cur_task = tasks[0]


    if r >= glo_max:
        return e * cur_task + dynamic(glo_max, r, tasks[1:])
    
    gain_max = 0
    for i in range(0, e+1):
        new_e = 0
        if e - i + r > glo_max:
            new_e = glo_max
        else:
            new_e = e - i + r
        cur_gain = i * cur_task + dynamic(new_e, r, tasks[1:])
        if cur_gain > gain_max:
            gain_max = cur_gain

    return gain_max
    

fin = open(sys.argv[1], "r")
cases = int(fin.readline())


    
for i in range(0, cases):
    e, r, _ = fin.readline().split()
    e, r = int(e), int(r)
    tasks = fin.readline().split()
    tasks = [int(x) for x in tasks]
    glo_max = e
    gain = dynamic(e, r, tasks)
    # print "*" * 72
    # print e,r
    # print tasks
    print "Case #%d: %d" % (i + 1, gain)
    
