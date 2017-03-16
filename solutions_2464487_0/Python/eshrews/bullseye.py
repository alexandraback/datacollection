#!/usr/bin/python

import fileinput

case = 1
for linenum, line in enumerate(fileinput.input()):
    if linenum == 0:
        cases = int(line)
        continue

    l = [int(x) for x in line.split()]
    r = l[0]
    t = l[1]
    result = 0
    while t > 0:
        paint = (r + 1)**2 - (r)**2
        if paint <= t:
            result += 1
        r += 2
        t -= paint

    print "Case #{0}: {1}".format(linenum, result)

    if case == cases:
        break
