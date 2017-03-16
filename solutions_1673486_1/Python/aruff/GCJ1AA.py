for T in xrange(input()):
	A,B = map(int,raw_input().split())
	p = map(float,raw_input().split())+[0]
	pk = 1
	m = B+2
	for k in xrange(A+1):
		m = min(m,B+A-2*k+1+(1-pk)*(B+1))
		pk*=p[k]
	print "Case #%d: %f"%(T+1,m)
