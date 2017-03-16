
tot = int(raw_input())
for t in xrange(tot):
	l = map(int, raw_input().split())
	n = l[0]
	s = l[1]
	p = l[2]
	ts = l[3:]
	ts.sort()
	ans = 0
	for ti in ts:
		if p*3-2 <= ti and ti >= p:
			ans += 1
		elif p*3 - 4 <= ti and ti >= p and s > 0:
			s -= 1
			ans += 1
	print 'Case #%d: %d' % (t+1, ans)
