#!/usr/bin/env python

import sys

with open(sys.argv[1]) as f:
    x = 1
    f.readline()
    for line in f:
        stack = map(lambda i: True if i == '+' else False, line.strip().rstrip('+')[::-1])
        result = 0
        last = True
        for i in stack:
            if last != i:
                last = i
                result += 1
        print "Case #%d: %d" % (x, result)
        x += 1

