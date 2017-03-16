for test in range(input()):
	A,B = map(int,raw_input().split())
	p = map(float,raw_input().split())
	P = [1]
	for i in xrange(A):
		P += [P[i]*p[i]]
	print "Case #%d: %.20f"%(test+1,min(min((2*i+B-A+1)+(1-P[-i-1])*(B+1)for i in range(A+1)),B+2))
	