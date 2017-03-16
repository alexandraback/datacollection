#!/usr/bin/python2.7

import sys

T = int(sys.stdin.readline())

for i in xrange(T):
    line   = sys.stdin.readline().strip()
    n_flip = 0
    cur    = '+'
    for d in xrange(len(line)-1,-1,-1):
        if line[d] != cur:
            n_flip += 1
        cur = line[d]
    print "Case #{0}: {1}".format((i+1), n_flip)
    


