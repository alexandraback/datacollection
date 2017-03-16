t = input()

for q in xrange(1, t+1):
	s = raw_input()
	ans = s[0]
	for i in s[1:]:
		if ord(i) < ord(ans[0]):
			ans = ans + i
		else:
			ans = i + ans
	print 'Case #{}: {}'.format(q, ans)