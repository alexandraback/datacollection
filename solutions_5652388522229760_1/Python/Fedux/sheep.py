#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import division
from fileparser import FileParser

def solve(n):
    if n == 0:
        return False

    digits = set("0123456789")

    i = 0
    while len(digits) > 0:
        i += 1
        digits -= set(str(n * i))
        #print "{} {} {} --> {}".format(i, n * i, set(str(n * i)), digits)

    return n * i

inputfile = FileParser()
T = inputfile.read_int()
for test in range(1, T+1):
    N = inputfile.read_int()

    result = solve(N)

    if result:
        print "Case #{}: {}".format(test, result)
    else:
        print "Case #{}: INSOMNIA".format(test)
