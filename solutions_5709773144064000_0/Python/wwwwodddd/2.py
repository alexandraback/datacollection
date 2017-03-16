t = input()
for tt in range(t):
	print "Case #%d:"%(tt + 1),
	c, f, x = map(float, raw_input().split())
	z = 1e30
	s = 0
	for i in range(10000):
		z = min(z, s + x / (2 + i * f))
		s += c / (2 + i * f)
	print "%.7f"%z