#!/usr/bin/python

import sys

def read_obj(cls):
    return cls(sys.stdin.readline().strip())

def read_obj_list(cls):
    return map(cls, sys.stdin.readline().strip().split())

def solve():
    t = read_obj(int)
    for i in xrange(1, t + 1):
        a, b, k = read_obj_list(int)
        res = 0
        for j in xrange(a):
            for l in xrange(b):
                if j & l < k:
                    res += 1
        print "Case #%d: %d" % (i, res)


if __name__ == "__main__":
    solve()
