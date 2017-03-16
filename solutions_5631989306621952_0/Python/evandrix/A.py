#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

T = int(sys.stdin.readline())
for t in xrange(1,T+1):
	print "Case #%d:"%t,
	S = raw_input()
	u = [S[0]]
	for s in S[1:]:
		x1 = u
		x2 = [s] + u
		x3 = u + [s]
		if len(u) == 0:
			u = sorted(map(lambda x: "".join(x), [x2, x3]))[-1]
		else:
			u = sorted(map(lambda x: "".join(x), [x1, x2, x3]))[-1]
		u = list(u)
	print "".join(u)
