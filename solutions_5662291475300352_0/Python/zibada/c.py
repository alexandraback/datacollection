def solve():
	n = int(raw_input())
	h = []
	for i in xrange(n):
		a, c, m = map(int, raw_input().split())
		for j in xrange(c):
			h.append([a, m + j])
	if len(h) < 2: return 0
	m1 = h[0][1]
	m2 = h[1][1]
	t1 = (360 - h[0][0]) * 1.0 / 360 * m1
	t2 = (360 - h[1][0]) * 1.0 / 360 * m2
	if t1 > t2:
		t1, t2 = t2, t1
		m1, m2 = m2, m1
	if t2 + 1e-9 < t1 + m1: return 0
	return 1
		

for i in xrange(input()):
	print "Case #%d: %d" % (i + 1, solve())
