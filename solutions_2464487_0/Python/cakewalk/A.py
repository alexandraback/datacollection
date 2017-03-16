T = int(raw_input())

for i in xrange(T):
	r, t = map(int, raw_input().split())
	nu = 10**18
	nl = 1
	while nu - nl > 1:
		nm = (nu + nl)/2
		if nm*(2*r-3) + 2*nm*(nm+1) > t:
			nu = nm
		else:
			nl = nm
	if nu*(2*r - 3) + 2*nu*(nu+1) <= t:
		ans = nu
	else:
		ans = nl
	print 'Case #%d: %d' % (i+1, ans)
