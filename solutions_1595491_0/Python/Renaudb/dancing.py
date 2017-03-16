#!/usr/bin/python2.7

import sys


def parse(case):
    case = case.split()

    s = int(case[1])
    p = int(case[2])
    points = [int(point) for point in case[3:]]

    return s, p, points


def maximize(s, p, points):
    if p < 0 or p > 10:
        return 0

    n = 0
    for point in points:
        if point == 0:
            if point / 3 >= p:
                n += 1
        elif point % 3 == 0:
            if point / 3 >= p:
                n += 1
            elif point / 3 + 1 >= p and s > 0:
                n += 1
                s -= 1
        elif point % 3 == 1:
            if point / 3 + 1 >= p:
                n += 1
        elif point % 3 == 2:
            if point / 3 + 1 >= p:
                n += 1
            elif point / 3 + 2 >= p and s > 0:
                n += 1
                s -= 1

    return n


f = open(sys.argv[1])
i = 1
for case in f.readlines()[1:]:
    s, p, points = parse(case)
    print "Case #%d: %d" % (i, maximize(s, p, points))
    i += 1
