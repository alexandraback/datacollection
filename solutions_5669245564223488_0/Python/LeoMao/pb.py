#! /usr/bin/env python

import string
import collections
import math

T = int(input())

for tt in range(1, T+1):
    n = int(input())
    cars = input().split()
    fflag = False
    lrfree = collections.Counter()
    ll = set()
    rr = set()
    inner = set()
    lrc = []
    for car in cars:
        if car[0] != car[-1]:
            if car[0] in ll or car[-1] in rr:
                fflag = True
                break
            ll.add(car[0])
            rr.add(car[-1])
            lrc.append((car[0], car[-1]))
        else:
            if car.count(car[0]) != len(car):
                fflag = True
                break
            lrfree[car[0]] += 1
    if fflag:
        print("Case #{}: 0".format(tt))
        continue
    for car in cars:
        if len(car) == 1:
            continue
        l, r = car[0], car[-1]
        temp = iter(car)
        for c in temp:
            if c != l:
                prev = c
                break
        for c in temp:
            if c == r:
                break
            elif c != prev:
                if c in inner or c in ll or c in rr:
                    fflag = True
                    break
                else:
                    inner.add(prev)
                    prev = c
        for c in temp:
            if c != r:
                fflag = True
                break
        if fflag:
            break
    if fflag:
        print("Case #{}: 0".format(tt))
        continue
    
    if lrc:
        now = list(lrc.pop())
        freecars = 1
    else:
        freecars = 0
    connected = rr | ll
    while lrc:
        for pa in lrc:
            if pa[0] == now[1]:
                now[1] = pa[1]
                lrc.remove(pa)
                break
            elif pa[1] == now[0]:
                now[0] = pa[0]
                lrc.remove(pa)
                break
        else:
            freecars += 1
            if lrc:
               now = list(lrc.pop())
    
    ans = 1
    for lrf, cnt in lrfree.items():
        if lrf not in connected:
            freecars += 1
        ans *= math.factorial(cnt)
    ans *= math.factorial(freecars)
    print("Case #{}: {}".format(tt, ans))
