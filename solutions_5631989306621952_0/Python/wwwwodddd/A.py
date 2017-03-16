t = input()
for tt in range(t):
	s = raw_input()
	z = ''
	for i in s:
		z = max(z + i, i + z)
	print 'Case #%d: %s' % (tt + 1, z)
	