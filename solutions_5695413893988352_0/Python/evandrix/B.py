#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from collections import defaultdict

Ls = []
def gen(L):
	if "?" not in L:
		N = "".join(map(str, L))
		Ls.append(N)
		return
	iq = L.index("?")
	for i in xrange(10):
		LL = L[:]
		LL[iq] = i
		gen(LL)

T = int(sys.stdin.readline())
for t in xrange(1,T+1):
	print "Case #%d:"%t,
	S = raw_input()
	C, J = S.split(" ")
	C, J = list(C), list(J)

	Ls = []
	gen(C)
	cs = Ls[:]

	Ls = []
	gen(J)
	js = Ls[:]

	lookup = defaultdict(list)
	for a in cs:
		for b in js:
			ab = abs(int(a)-int(b))
			lookup[ab].append((int(a),int(b),a,b))

	smallest = sorted(lookup.keys())[0]
#	print smallest, sorted(lookup[smallest])
	A, B, AA, BB = sorted(lookup[smallest])[0]
	print AA, BB
