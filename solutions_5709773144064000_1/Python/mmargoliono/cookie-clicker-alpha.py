#!/usr/bin/env python

import sys

T = int(sys.stdin.readline())

for t in range (1, T+1):
    data = sys.stdin.readline().split(" ")
    cost = float(data[0])
    inc = float(data[1])
    target = float(data[2])
    time = 0
    best = sys.float_info.max
    cookie = 2.0
    while (True):
        remaining = target / cookie
        current = time + remaining
        if (current < best):
            best = current
            buy_farm_time = cost / cookie
            time += buy_farm_time
            cookie += inc
        else:
            break

    print ("Case #{case}: {time:.7f}".format(case = t, time=best))
