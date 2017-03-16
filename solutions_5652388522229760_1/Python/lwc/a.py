t = input()
for cs in xrange(1, t+1):
	n = input()
	if n == 0:
		ans = 'INSOMNIA'
	else:
		mask = 0
		ans = 0
		while mask != 1023:
			ans += n
			for c in str(ans):
				mask |= 1 << (ord(c)^48)
		ans = str(ans)
	print 'Case #%d: ' % cs + ans
