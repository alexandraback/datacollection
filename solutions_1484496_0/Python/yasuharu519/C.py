#!/usr/bin/env python
# -*- coding:utf-8 -*-
import sys, os
import operator
import itertools
TEMPLATE = "Case #%d:"
Anss = dict()

def decode(r):
    Aset = [int(x) for x in r.readline().rstrip().split()]
    return (Aset[0], Aset[1:])

def solve(N, Sset):
    isFound = False
    for i in range(1, N):
	    for can in itertools.combinations(Sset, i):
		    key = sum(can)
		    if Anss.has_key(key):
			    for aaa in Anss[key]:
				    print aaa,
			    print
			    for bbb in can:
				    print bbb,
			    print 
			    isFound = True
			    break
		    else:
			    Anss[key] = can
	    if isFound:
		    break
    if isFound == False:
	    print "Impossible"

if __name__ == "__main__":
    filename = sys.argv[1]
    with open(filename) as r:
        T = int(r.readline().rstrip())
        for i in xrange(T):
	    N, Sset = decode(r)
	    print TEMPLATE % (i + 1,)
	    solve(N, Sset)
