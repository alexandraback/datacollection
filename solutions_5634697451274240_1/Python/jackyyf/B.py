T = input()

for i in range(T):
	S = raw_input()
	now = S[0]
	print 'Case #%d:' % (i + 1),
	ans = 0
	for ch in S:
		if now != ch:
			ans += 1
		now = ch
	if ch == '-':
		ans += 1
	print ans
