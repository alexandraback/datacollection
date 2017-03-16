#!/usr/bin/env python

import sys

def R(f):
    with open(f,"r") as fin:
        return fin.read().splitlines()

def solve(line):
    p = '+'
    ct = 0
    for i in xrange(1, len(line)+1):
        a = line[-i]
        if a != p:
            ct += 1
        p = a

    return ct

if len(sys.argv) != 2:
    print "usage: %s input_file" % sys.argv[0]
    exit()


ss = R(sys.argv[1])

T = int(ss[0])

for i in xrange(1, T+1):
    print "Case #%d:" %i, solve( ss[i] )

