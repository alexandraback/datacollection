#!/usr/bin/python3

import sys
import random

ncases = int(sys.stdin.readline().strip())

for t in range(1, ncases+1):
    values = sys.stdin.readline().strip().split()
    j = int(values[0])
    p = int(values[1])
    s = int(values[2])
    k = int(values[3])

    best_result = []

    for attempt in range(0, 100):
        jp = {}
        ps = {}
        sj = {}

        combinations = []
        for jn in range(1, j+1):
            for pn in range(1, p+1):
                for sn in range(1, s+1):
                    if jn not in jp: jp[jn] = {}
                    if pn not in ps: ps[pn] = {}
                    if sn not in sj: sj[sn] = {}

                    if pn not in jp[jn]: jp[jn][pn] = 0
                    if sn not in ps[pn]: ps[pn][sn] = 0
                    if jn not in sj[sn]: sj[sn][jn] = 0

                    combinations.append([jn, pn, sn])

        solutions = []
        kgoal = 1
        while combinations and kgoal <= k:
            pending_combinations = []
            random.shuffle(combinations)
            for c in combinations:
                if jp[c[0]][c[1]] < kgoal and ps[c[1]][c[2]] < kgoal and sj[c[2]][c[0]] < kgoal:
                    solutions.append(str(c[0]) + " " + str(c[1]) + " " + str(c[2]))
                    jp[c[0]][c[1]] += 1
                    ps[c[1]][c[2]] += 1
                    sj[c[2]][c[0]] += 1
                else:
                    pending_combinations.append(c)
            combinations = pending_combinations
            kgoal += 1

        if len(solutions) > len(best_result):
            best_result = solutions

    print("Case #{0}: {1}".format(t, len(best_result)))
    for s in best_result:
        print(s)

