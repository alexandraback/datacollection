#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import fractions

def solve(n, m, k):
    if n <= 2 or m <= 2 or k <= 4:
        return k
    if n == 3 and m == 3:
        return k-1
    if k < 8:
        return k-1
    if n <= 3 or m <= 3:
        if k < 11:
            return k-2
        if k < 14:
            return k-3
        if k < 17:
            return k-4
        if k < 20:
            return k-5
    
    if k < 10:
        return k-2
    if k < 12:
        return k-3
    if k < 14:
        return k-4
    if n == 4 and m == 4:
        return k-4
    if k < 16:
        return k-5
    if k >= 16:
        return k-6

if __name__ == "__main__":
    with open(sys.argv[1]) as f:
        buf = f.read()
    t = buf.split("\n")
    nb_boards = int(t[0])
    t = t[1:]
    for l in xrange(0, nb_boards):
        n, m, k = map(int, t[l].split(' '))
        print "Case #%d: %s"%(l+1, solve(n, m, k))
