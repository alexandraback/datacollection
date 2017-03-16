#!/usr/bin/env python

import os, sys


def solve (line):
    cs = line[0]
    cps = line[1:]

    curall = float(sum(cps))
    all = (curall*2.0)
    per = all / cs
    res = [(per-x)/curall*100 for x in cps]

    neg = 0
    for x in res:
        if x < 0:
            neg += x

    poscnt = len([x for x in res if x > 0])

    resout = []
    neg /= poscnt
    for x in res:
        if x > 0:
            resout.append(str(x+neg))
        else:
            resout.append(str(0.0))


    return " ".join(resout)


fd = sys.stdin

line = fd.readline()
sets = int(line)+1

for case in range(1, sets):
    line = [float(x) for x in fd.readline().strip().split()]
    nline = solve(line)
    print "Case #%s: %s" % (case, nline)

fd.close()
