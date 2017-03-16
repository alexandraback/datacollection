#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from collections import defaultdict

T = int(sys.stdin.readline())
for t in xrange(1,T+1):
	print "Case #%d:"%t,
	N = int(raw_input())

	Ls = []
	for i in xrange(2*N-1):
		Ls.append(map(int, raw_input().split(" ")))
#	print Ls

	lookup = defaultdict(int)
	for i in xrange(2*N-1):
		for c in Ls[i]:
			lookup[c] += 1
#	print lookup

	ks = []
	for k,v in lookup.iteritems():
		if v % 2 == 1:
			ks.append(k)
	print " ".join(map(str, sorted(ks)))

