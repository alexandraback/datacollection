#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

digits = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
digits = map(lambda d: list(d), digits)

T = int(sys.stdin.readline())
for t in xrange(1,T+1):
	print "Case #%d:"%t,
	S = raw_input()
	S = list(S)

	res = []
	for a, b in [("Z",0), ("W",2), ("U",4), ("X",6), ("G",8)]:
		while a in S:
			i = b
			for c in digits[i]: S.remove(c)
			res.append(i)

	for a, b in [("O",1), ("H",3), ("F",5), ("S",7)]:
		while a in S:
			i = b
			for c in digits[i]: S.remove(c)
			res.append(i)

	while len(S) > 0:
		i = 9
		for c in digits[i]: S.remove(c)
		res.append(i)

	print "".join(map(str, sorted(res)))
