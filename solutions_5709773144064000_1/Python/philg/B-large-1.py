#!/usr/bin/python

import sys

PROBLEMSIZE=int(sys.stdin.readline())

for i in range(PROBLEMSIZE):
    c, f, x = [float(num) for num in sys.stdin.readline().split(" ")]
    farmcount = 0
    buyTimes = [0.0]
    income = lambda farms: (2.0 + farms * f)
    timeToBuy = lambda farms: (c / income(farms))
    estTime = lambda farms: buyTimes[farms] + (x / (2.0 + farms * f))
    buyTimes.append(timeToBuy(farmcount)+buyTimes[farmcount])
    while estTime(farmcount) > estTime(farmcount+1):
        farmcount += 1
        buyTimes.append(timeToBuy(farmcount)+buyTimes[farmcount])
    print("Case #%s: %.7f"%((i+1),estTime(farmcount)))
