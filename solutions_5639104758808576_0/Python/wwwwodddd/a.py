t = input()
for i in range(t):
	l, s = raw_input().split()
	l = int(l)
	w = 0
	z = 0
	for j in range(l + 1):
		if j > w:
			z += j - w
			w = j
		w += int(s[j])
	print 'Case #%d: %d' % (i + 1, z)