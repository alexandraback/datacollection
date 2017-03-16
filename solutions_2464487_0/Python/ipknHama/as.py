tn = input()
for loop in xrange(tn):
	print 'Case #%d:'%(loop+1),
	R, T = [int(x) for x in raw_input().split()]
	#begin with r+1
# for r
	# r^2 - (r-1)^2 = 2r-1 
# 2 4
# 3, 7, 
# r+1, r+3, r+5, ...
# 2*r+1, 2*r+5, 2*r+9, ... 2*r - 3 + 4*k
# 2*r*k -3*k + 2 * 
	k = 1
	l = 1
	r = 1
	while T >= 2*r*R+r*(r+1)*2-3*r:
		r *= 2
	while l < r:
		m = (l+r)//2
		if 2*m*R+m*(m+1)*2-3*m <= T:
			k = m
			l = m+1
		else:
			r = m
	print k



