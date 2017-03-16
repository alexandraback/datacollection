#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

T = int(sys.stdin.readline())
for t in xrange(1,T+1):
	print "Case #%d:"%t,

	N = int(raw_input())

	As, Bs = set(), set()
	lines = []
	for i in xrange(N):
		S = raw_input()
		A, B = S.split(" ")
		As.add(A)
		Bs.add(B)
		lines.append((A,B))

	w, h = len(Bs), len(As)
	adj = [[0 for _ in xrange(w)] for _ in xrange(h)]
	As = list(As)
	Bs = list(Bs)
	for line in lines:
		A, B = line
		a = As.index(A)
		b = Bs.index(B)
		adj[a][b] += 1

	ans = 0
	for r in xrange(h):
		if sum(adj[r]) > 1: ans += 1
	print ans
