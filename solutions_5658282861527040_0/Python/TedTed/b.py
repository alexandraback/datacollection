#!/usr/bin/python
# -*- coding: utf-8 -*-



nbcases = int(raw_input())

for case in xrange(1,nbcases+1):
    [a,b,k] = [eval (n) for n in raw_input().strip().split(" ")]
    nbok = 0
    for i in xrange(0,a):
        for j in xrange(0,b):
            if (i&j < k):
                nbok += 1
    print "Case #%d: %d" % (case,nbok)

