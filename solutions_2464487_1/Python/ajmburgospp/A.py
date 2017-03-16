T = int(raw_input())
for kei in xrange(T):
	r, t = (int(x) for x in raw_input().split())
	def f(k):
		return 2*k**2 + (2*r-1)*k
	low, high = 1, t
	while high-low > 1:
		g = (low+high) / 2
		fg = f(g)
		if fg < t:
			low = g
		elif fg == t:
			low = high = g
		else:
			high = g
	if f(high) <= 0:
		print('Case #%d: %d' % (kei+1, high))
		#print(f(high), f(high+1))
	else:
		print('Case #%d: %d' % (kei+1, low))
		#print(f(low), f(low+1))