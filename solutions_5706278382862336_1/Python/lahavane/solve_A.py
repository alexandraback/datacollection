#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import fractions

def solve(p, q):
    g = fractions.gcd(p, q)
    p /= g
    q /= g
    if q%2 != 0 and p != q:
        return 'impossible'
    res = 0
    while (q % 2) == 0 and p < q:
        q /= 2
        res += 1
    if q%2 != 0 and p != q:
        return 'impossible'
    return res

if __name__ == "__main__":
    with open(sys.argv[1]) as f:
        buf = f.read()
    t = buf.split("\n")
    nb_boards = int(t[0])
    t = t[1:]
    for k in xrange(0, nb_boards):
        p, q = map(int, t[k].split('/'))
        print "Case #%d: %s"%(k+1, solve(p, q))
