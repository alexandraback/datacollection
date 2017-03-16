t = input()
for cs in xrange(1, t+1):
	s = raw_input()[-1::-1]
	ans = 0
	for c in s:
		ans += [0, 1][(c == '-') ^ (ans & 1)]
	print 'Case #%d: ' % cs + str(ans)
