#!/usr/bin/env python

import sys

with open(sys.argv[1]) as f:
    f.readline()
    x = 1
    for line in f:
        base = int(line)
        current = 0
        status = [False] * 10
        while not all(status) and base != 0:
            current += base
            for digit in map(int, str(current)):
                status[digit] = True
        print "Case #%d: %s" % (x, str(current) if all(status) else "INSOMNIA")
        x += 1

