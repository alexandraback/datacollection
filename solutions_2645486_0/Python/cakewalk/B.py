def solve(Erem, i):
	try:
		return solvedict[(Erem, i)]
	except:
		if i == N-1:
			ans = Erem*v[i]
		else:
			ans = max((e*v[i] + solve(min(E, Erem-e+R), i+1) for e in xrange(Erem+1)))
		solvedict[(Erem, i)] = ans
		return ans

T = int(raw_input())

for t in xrange(T):
	E, R, N = map(int, raw_input().split())
	v = map(int, raw_input().split())
	solvedict = {}
	print 'Case #%d: %d' % (t+1, solve(E, 0))
