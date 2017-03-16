#!/usr/bin/env python

import sys

def R(f):
    with open(f,"r") as fin:
        return fin.read().splitlines()

def solve(line):
    K,C,S = map(int, line.split())
    if S < K:
        return "IMPOSSIBLE"

    Base = K ** (C-1)
    res = [ 1 + Base * i for i in xrange(K) ]
    return " ".join([str(x) for x in res])


if len(sys.argv) != 2:
    print "usage: %s input_file" % sys.argv[0]
    exit()


ss = R(sys.argv[1])

T = int(ss[0])

for i in xrange(1, T+1):
    print "Case #%d:" %i, solve( ss[i] )

