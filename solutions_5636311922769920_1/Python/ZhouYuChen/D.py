#!/usr/bin/env pypy

def sol(K, C, S):
	u, r = 0, []
	while u < K and S > 0:
		t = 0
		for j in xrange(C):
			t, u = t * K + min(u, K-1), u+1
		S -= 1
		r = r + [t+1]

	if u < K:
		return "IMPOSSIBLE"

	while len(r) < S:
		for j in xrange(1, K**C+1):
			if j not in r:
				r = r + [j]
				break
	return " ".join(map(str,r))

for t in xrange(1, input()+1):
	K, C, S = map(int, raw_input().split())
	print "Case #%d: %s" % (t, sol(K, C, S))
