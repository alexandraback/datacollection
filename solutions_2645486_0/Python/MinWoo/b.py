
def solve(e, g, i):
	global E, R, N, res
	#print e, g, i
	if i == N:
		res = max(res, g)
		return

	for x in xrange(e+1):
		solve(min(E, e-x+R), g+x*V[i], i+1)

T = input()
for tc in xrange(T):
	E, R, N = map(int, raw_input().split())
	V = map(int, raw_input().split())
	res = 0
	solve(E, 0, 0)
	print 'Case #%d: %d' % (tc+1, res)

