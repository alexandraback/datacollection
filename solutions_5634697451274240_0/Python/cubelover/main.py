for _ in range(1, int(input()) + 1):
	print('Case #%d:' % _, end = ' ')
	s = input()+'+'
	r = 0
	for i in range(1, len(s)):
		if s[i] != s[i-1]:
			r += 1
	print(r)