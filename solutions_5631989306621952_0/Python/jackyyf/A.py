T = input()

for i in range(T):
	s = raw_input()
	print 'Case #%d:' % (i + 1),
	final = s[0]
	for ch in s[1:]:
		if final[0] <= ch:
			final = ch + final
		else:
			final += ch

	print final
