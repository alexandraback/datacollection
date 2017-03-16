def readints(): return map(int, raw_input().split())
def solve(D, P):
	return min(x + sum((y - 1) / x for y in P) for x in xrange(1, max(P)+1))

T, = readints()
for case_num in range(1, T+1):
	D, = readints()
	P = readints()
	print "Case #%d: %d" % (case_num, solve(D, P))