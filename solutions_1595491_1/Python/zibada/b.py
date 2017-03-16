def solve():
	d = map(int, raw_input().split())
	(n, s, p), a = d[:3], d[3:]
	res = 0
	for x in a:
		if x >= (p - 1) * 3 + 1:
			res += 1
		elif s and x >= max(0, (p - 2)) * 2 + p:
			res += 1
			s -= 1
	return res

for i in xrange(input()):
	print "Case #%d: %d" % (i + 1, solve())
