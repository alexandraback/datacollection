#!/usr/bin/env python
# -*- coding:utf-8 -*-
import sys, os
import operator
TEMPLATE = "Case #%d:"
def decode(r):
    Aset = [int(x) for x in r.readline().rstrip().split()]
    return (Aset[0], Aset[1:])

def solve(N, Sset):
    X = sum(Sset)
    toValue = X * 2 / float(N)
    num = 0
    if toValue < max(Sset):
        num = sum([1 for x in Sset if x >= toValue])
	toValue = (X + sum([x for x in Sset if x <= toValue]))  / float((N - num))
    ans = [float((toValue - x)) / X * 100 for x in Sset]
    ans = [(lambda x: 0.0000000 if x <= 0.0 else x)(x) for x in ans]
    for i in ans:
        print "%.6f" % (i, ),

if __name__ == "__main__":
    filename = sys.argv[1]
    with open(filename) as r:
        T = int(r.readline().rstrip())
        for i in xrange(T):
	    N, Sset = decode(r)
	    print TEMPLATE % (i + 1,),
	    solve(N, Sset)
	    print
