#!/usr/bin/env python

import os, sys


cs = set()
def paths(classes, num, path=[]):
    path = path[:]
    path.append(num)

    if classes[num]:
        for x in classes[num]:
            paths(classes, x, path)
    else:
        cs.add(str(path))


def solve (num, classes):

    global cs

    for k in classes.keys():
        cs = set()
        paths(classes, k)
        #print cs

        lcs = [eval(x) for x in list(cs)]
        lcs = [x for x in lcs if len(x) > 1]
        lcs = [(x[0], x[-1]) for x in lcs]

        if len(lcs) > len(set(lcs)):
            return "Yes"
    return "No"

fd = sys.stdin

line = fd.readline()
sets = int(line)+1

for case in range(1, sets):
    line = int(fd.readline().strip())

    classes = {}
    for l in range(line):
        classes[l+1] = [int(x) for x in fd.readline().strip().split()][1:]

    nline = solve(line, classes)
    print "Case #%s: %s" % (case, nline)

fd.close()
