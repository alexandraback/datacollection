#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

T = int(sys.stdin.readline())
for t in xrange(1,T+1):
	print "Case #%d:"%t,
	K, C, S = map(int, raw_input().split(" "))

	print " ".join(map(str, list(xrange(1,K+1))))
#	for i in xrange(S):
#		print 1+i+i*K**(C-1),
#	print
