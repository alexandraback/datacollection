from __future__ import division

for T in xrange(int(raw_input())):
	S = map(int, raw_input().split())
	N = S.pop(0)
	S_t = sum(S)
	
	ans = []

	for i, s in enumerate(S):
		pmin = 0.0
		pmax = 1.0
		while abs(pmin - pmax) > 1E-10:
			pmid = (pmin + pmax) / 2
			p = 1.0 - pmid
			less = [z for j, z in enumerate(S) if z <= s + S_t * pmid and j != i]
			for z in less:
				q = (s + S_t * pmid - z) / S_t
				p -= q
			if p >= 0:
				pmin = pmid
			else:
				pmax = pmid
		ans.append(pmid * 100)

	print "Case #%d: %s" % (T + 1, " ".join(["%.6f" % s for s in ans]))

'''
4
2 20 10
2 10 0
4 25 25 25 25
3 24 30 21

Case #1: 33.333333 66.666667
Case #2: 0.000000 100.000000
Case #3: 25.0 25.0 25.0 25.0
Case #4: 34.666667 26.666667 38.666667
'''	
