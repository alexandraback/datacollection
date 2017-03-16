import math;


T = input()
for ca in xrange (1,T+1):
	r, t = map(int, raw_input().split());
	low = 0
	up = 2000000000
	while up > low:
		m = (up + low + 1) / 2;
		if (2*r+1+2*m) * (m+1) <= t:
			low = m
		else:
			up = m - 1;

	print 'Case #' + str(ca) + ': ' + str(low + 1)

		
#		if math.log(2*r+1+2*m) + math.log(m+1) <= math.log(t):	
