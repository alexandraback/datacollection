t = input()
for tt in range(t):
	print "Case #%d:"%(tt + 1),
	c, f, x = map(float, raw_input().split())
	z = 1e30
	s = 0
	i = 0
	while True:
		z = min(z, s + x / (2 + i * f))
		s += c / (2 + i * f)
		if s > z:
			break
		i += 1
	print "%.7f"%z