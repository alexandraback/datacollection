#

T = int(raw_input())

for t in xrange( 1, T+1 ):
	
	A,N = map(int, raw_input().split())
	motes = map(int, raw_input().split())
	motes.sort()
	
	best = N
	if A > 1:
		c = 0
		for i in xrange(N):
			while A <= motes[i]:
				A += A-1
				c += 1
			A += motes[i]
			best = min(best, c+(N-i-1))
	
	print "Case #%d: %d" %(t, best)
