for i in range(int(raw_input())):
	inp = map(int, raw_input().split())
	
	s = inp[1]
	p = inp[2]
	
	normal = p + 2 * max(p - 1, 0)
	surprising = p + 2 * max(p - 2, 0)
	
	r = 0
	for t in inp[3:]:
		if normal <= t:
			r += 1
		elif surprising <= t and s > 0:
			r += 1
			s -= 1
	
	print 'Case #%d: %d' % (i + 1, r)
