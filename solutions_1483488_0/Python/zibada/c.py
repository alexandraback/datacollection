def solve():
	a, b = map(int, raw_input().split())
	res = 0
	for i in xrange(a, b + 1):
		l = len(str(i))
		s = set()
		for p in xrange(1, l):
			e = 10 ** p
			m = i / e + (i % e) * (10 ** (l - p))
			if m <= i or m > b: continue
			s.add(m)
		res += len(s)
	return res
for i in xrange(input()):
	print "Case #%d: %d" % (i + 1, solve())
