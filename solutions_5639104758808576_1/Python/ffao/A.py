for case in xrange(int(raw_input())):
	print "Case #%d:" % (case+1),

	sm, s = raw_input().split()

	curr = 0
	ans = 0
	for i, x in enumerate(s):
		if curr < i:
			ans += (i - curr)

		curr = max(curr, i)
		val = ord(x) - ord('0')
		curr += val

	print ans