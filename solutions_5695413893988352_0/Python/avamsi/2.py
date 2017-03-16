for t in xrange(1, int(raw_input()) + 1):
	print 'Case #%s:' % t,
	c, j = raw_input().split()
	ci = c.count('?')
	ji = j.count('?')
	cf = c.replace('?', '%s')
	jf = j.replace('?', '%s')

	out = []

	if ci == 0:
		ic = int(c)
		for i2 in xrange(10**ji):
			ij = int(jf % tuple('%0*d' % (ji, i2)))
			out.append((abs(ic - ij), ic, ij))

	elif ji == 0:
		ij = int(j)
		for i1 in xrange(10**ci):
			ic = int(cf % tuple('%0*d' % (ci, i1)))
			out.append((abs(ic - ij), ic, ij))

	else:
		for i1 in xrange(10**ci):
			for i2 in xrange(10**ji):
				ic = int(cf % tuple('%0*d' % (ci, i1)))
				ij = int(jf % tuple('%0*d' % (ji, i2)))
				out.append((abs(ic - ij), ic, ij))

	a = min(out)
	print '%0*d %0*d' % (len(c), a[1], len(j), a[2])
