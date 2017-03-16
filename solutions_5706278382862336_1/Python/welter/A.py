#!/usr/bin/python

import sys
from fractions import *

def read_obj(cls):
    return cls(sys.stdin.readline().strip())

def read_obj_list(cls):
    return map(cls, sys.stdin.readline().strip().split())

def solve():
    t = read_obj(int)
    for i in xrange(1, t + 1):
        fr = Fraction(read_obj(str))
        if fr.denominator & (fr.denominator - 1):
            print "Case #%d: impossible" % i
            continue
        res = 0
        while fr != 1:
            fr += min(fr, 1 - fr)
            res += 1
        print "Case #%d: %d" % (i, res)


if __name__ == "__main__":
    solve()
