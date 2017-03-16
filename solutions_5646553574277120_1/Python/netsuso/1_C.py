#!/usr/bin/python3

import sys
import heapq

ncases = int(sys.stdin.readline().strip())

for t in range(1, ncases+1):
    values = sys.stdin.readline().split()
    c = int(values[0])
    v = int(values[2])
    values = sys.stdin.readline().split()
    base_denominations = [int(x) for x in values]

    denominations = []
    for d in base_denominations:
        for i in range(1, c+1):
            denominations.append(d*i)

    heapq.heapify(denominations)

    extra = 0
    achievable = 0
    while achievable < v:
        if len(denominations) == 0 or min(denominations) > (achievable + 1):
            #print("Max achievable is {} and next denomination is {}".format(achievable, min(denominations)))
            extra += 1
            extravalue = achievable + 1
            for i in range(1, c+1):
                heapq.heappush(denominations, i * extravalue)
        else:
            coin = heapq.heappop(denominations)
            achievable += coin

    print("Case #{0}: {1}".format(t, extra))

