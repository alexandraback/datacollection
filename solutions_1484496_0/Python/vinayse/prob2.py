

def Solve(S, t):
	ans = {}
	for i in xrange(2**19):
		sofar = []
		for j in range(20):
			if ((1 << j) & i) > 0:
				sofar.append(S[j])
		s = sum(sofar)
		if s in ans:
			print "Case #%d:" % t
			print " ".join([str(x) for x in ans[s]])
			print " ".join([str(x) for x in sofar])
			return
		else:
			ans[s] = sofar
	print "Case #%d: Impossible" % t

import sys
f = sys.stdin
T = int(f.readline())

for i in xrange(1, T+1):
	segs = [int(x) for x in f.readline().split()]
	S = segs[1:]
	Solve(S, i)