T = int(raw_input())

for tc in xrange(T):
	r,t = map(int,raw_input().split())
	lb = 0 
	ub = 1000000000000000000000
	while ub-lb>1:
		mid = (lb+ub)/2
		m = 2*mid-1
		minus = 1 if m%2==0 else -1
		sum = 2*r*(-2*minus*m-minus+1)/4-(minus*m*(m+1))/2
		#print sum
		if sum<=t: lb = mid
		else: ub = mid
	print 'Case #%d: %d' % (tc+1,lb)
	