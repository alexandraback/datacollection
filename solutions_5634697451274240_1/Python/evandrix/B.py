#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

T = int(sys.stdin.readline())
for t in xrange(1,T+1):
	print "Case #%d:"%t,
	S = list(raw_input())
	SS = []
	for i, s in enumerate(S):
		if i > 0 and s == S[i-1]: continue
		SS.append(s)
	if len(SS) > 0 and SS[-1] == '+':
		SS = SS[:-1]
	print len(SS)
