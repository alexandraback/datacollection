f = open('B-large.in')
T = int(f.readline())
for t in range(1, T+1):
	C, F, X = map(float, f.readline().split())
	
	threshold_rate = F*(X-C)/C

	time_so_far = 0
	rate_now = 2

	while(rate_now < threshold_rate):
		time_so_far += C/rate_now
		rate_now += F

	time_total = time_so_far + X/rate_now
	print 'Case #%d: %s' % (t, '{0:.7f}'.format(time_total))
