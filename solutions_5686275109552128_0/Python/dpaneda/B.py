#!/usr/bin/python2

import sys
import bisect


def special_minutes(dinners):
    best_time = max(dinners)
    best_added = 0
    best = list(dinners)
    minutes = 0

    for i in xrange(len(dinners)):
        m = dinners.pop()
        pick = m / 2
        bisect.insort(dinners, m - pick)
        bisect.insort(dinners, pick)
        minutes += 1
        current_time = minutes + max(dinners)
        if current_time <= best_time:
            best = list(dinners)
            best_time = current_time
            best_added = minutes

    return best, best_added


def solve():
    sys.stdin.readline()
    dinners = map(int, sys.stdin.readline().split())
    dinners.sort()

    total_added = 0
    added = 1
    while added:
        dinners, added = special_minutes(dinners)
        total_added += added

    return total_added + max(dinners)

num = int(sys.stdin.readline())
for case in range(1, num + 1):
    print "Case #{0}: {1}".format(case, solve())
