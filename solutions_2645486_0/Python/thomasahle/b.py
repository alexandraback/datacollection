def f(e, n):
	if n == N: return 0
	res = -1000000000
	for i in range(e+1):
		res = max(res, f(min(e-i+R,E),n+1) + i*vs[n])
	return res

import sys
T = int(sys.stdin.readline())
for t in xrange(T):
	E, R, N = map(int, sys.stdin.readline().split())
	vs = map(int, sys.stdin.readline().split())
	print "Case #%d: %d" % (t+1, f(E, 0))
