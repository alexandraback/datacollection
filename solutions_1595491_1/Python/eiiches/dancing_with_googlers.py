# coding: utf-8

import sys

def solve(totals, n_surprising, at_least):
    result1 = 0
    result2 = 0

    for t in totals:

        added = False

        if t >= 0:
            for r in [0]:
                if (t + r) % 3 == 0:
                    if (t + r) // 3 >= at_least:
                        result1 += 1
                        added = True
                        break

        if added:
            continue

        if t >= 1:
            for r in [1, 2]:
                if (t + r) % 3 == 0:
                    if (t + r) // 3 >= at_least:
                        result1 += 1
                        added = True
                        break

        if added:
            continue

        if t >= 2:
            for r in [2, 3, 4]:
                if (t + r) % 3 == 0:
                    if (t + r) // 3 >= at_least:
                        result2 += 1
                        added = True
                        break

    return result1 + min(result2, n_surprising)

with open(sys.argv[1]) as f:
    for index, case in enumerate(filter(None, f.read().split('\n')[1:])):
        case = map(int, case.split())
        n_googlers = case[0]
        n_surprising = case[1]
        at_least = case[2]
        totals = case[3:]
        assert(n_googlers == len(totals))
        result = solve(totals, n_surprising, at_least)
        print 'Case #{0}: {1}'.format(index + 1, result)
