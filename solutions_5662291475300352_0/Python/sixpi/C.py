#!/usr/bin/env python3
import sys
from itertools import combinations

T = int(next(sys.stdin))


def next_intersection(hikers):
    min_time = None
    for a, b in combinations(hikers, 2):
        # a is always faster
        if a[1] == b[1]:
            continue

        if a[1] < b[1]:
            a,b = b,a

        dist = b[0] - a[0]
        while dist <= 0:
            dist += 360.0
        print("dist:", dist)
        time = dist / (a[1] - b[1])
        if min_time is None:
            min_time = time
        else:
            min_time = min(time, min_time)

    return min_time


for i in range(T):
    N = int(next(sys.stdin))

    hikers = []
    for j in range(N):
        l = next(sys.stdin)
        D, H, M = (float(s) for s in l.split())

        for k in range(int(H)):
            hikers.append([D, M+k])

    if len(hikers) == 1:
        print("Case #{}: {}".format(i+1, 0))
        continue

    hikers.sort()
    a, b = hikers
    assert b[0] > a[0] or b[1] > a[1]

    min_collides = 0
    ta, tb = [(360.0 - x[0])*x[1] for x in hikers]

    if ta > tb:
        if (720.0 - b[0])*b[1] > (360 - a[0])*a[1]:
            print("Case #{}: {}".format(i+1, 0))
            continue
    else:
        if (720.0 - a[0])*a[1] > (360 - b[0])*b[1]:
            print("Case #{}: {}".format(i+1, 0))
            continue

    print("Case #{}: {}".format(i+1, 1))
