#!/usr/bin/python

import sys
import re
import math
import fractions

f = open(sys.argv[1],'r')
num = int(f.readline())
for z in range(num):
    h,n,m = [int(x) for x in f.readline().split()]
    ceil = []
    for i in range(n):
        ceil.append([int(x) for x in f.readline().split()])
    floor = []
    for i in range(n):
        floor.append([int(x) for x in f.readline().split()])

    #print h,n,m
    #print ceil
    #print floor

    time_en_sl = []
    for i in range(n):
        line = []
        for j in range(m):
            if ceil[i][j]-floor[i][j] < 50:
                te = -1
            elif ceil[i][j] - h >= 50:
                te = 0
            else:
                te = float(50 + h - ceil[i][j]) / 10.0
            if floor[i][j] + 20 > h:
                ts = 0
            else:
                ts = float(h - floor[i][j] - 20) / 10.0
            line.append((te,ts))
        time_en_sl.append(line)
    #print time_en_sl
    time = []
    for i in range(n):
        time.append([-1]*m)
    time[0][0] = 0
    update = True
    while update:
        update = False
        for i in range(n):
            for j in range(m):
                if time[i][j] >= 0:
                    if i > 0 and (time[i-1][j] == -1 or time[i-1][j] > time[i][j]) and ceil[i][j] - floor[i-1][j] >= 50 and ceil[i-1][j] - floor[i][j] >= 50:
                        tn = max(time[i][j], time_en_sl[i-1][j][0])
                        if tn == 0:
                            ta = 0
                        elif tn <= time_en_sl[i][j][1]:
                            ta = tn+1
                        else:
                            ta = tn+10
                        if time[i-1][j] == -1 or ta < time[i-1][j]:
                            update = True
                            time[i-1][j] = ta
                    if i < n-1 and (time[i+1][j] == -1 or time[i+1][j] > time[i][j]) and ceil[i][j] - floor[i+1][j] >= 50 and ceil[i+1][j] - floor[i][j] >= 50:
                        tn = max(time[i][j], time_en_sl[i+1][j][0])
                        if tn == 0:
                            ta = 0
                        elif tn <= time_en_sl[i][j][1]:
                            ta = tn+1
                        else:
                            ta = tn+10
                        if time[i+1][j] == -1 or ta < time[i+1][j]:
                            update = True
                            time[i+1][j] = ta
                    if j < m-1 and (time[i][j+1] == -1 or time[i][j+1] > time[i][j]) and ceil[i][j] - floor[i][j+1] >= 50 and ceil[i][j+1] - floor[i][j] >= 50:
                        tn = max(time[i][j], time_en_sl[i][j+1][0])
                        if tn == 0:
                            ta = 0
                        elif tn <= time_en_sl[i][j][1]:
                            ta = tn+1
                        else:
                            ta = tn+10
                        if time[i][j+1] == -1 or ta < time[i][j+1]:
                            update = True
                            time[i][j+1] = ta
                    if j > 0 and (time[i][j-1] == -1 or time[i][j-1] > time[i][j]) and ceil[i][j] - floor[i][j-1] >= 50 and ceil[i][j-1] - floor[i][j] >= 50:
                        tn = max(time[i][j], time_en_sl[i][j-1][0])
                        if tn == 0:
                            ta = 0
                        elif tn <= time_en_sl[i][j][1]:
                            ta = tn+1
                        else:
                            ta = tn+10
                        if time[i][j-1] == -1 or ta < time[i][j-1]:
                            update = True
                            time[i][j-1] = ta

    #print time


    print 'Case #{}:'.format(z+1), time[n-1][m-1]
    sys.stdout.flush()
