def isConsonant(c):
	return False if c in 'aeiou' else True

T = input()
for case_no in range(1, T+1):
	name, n = raw_input().split()
	n = int(n)
	L = len(name)
	left  = 0
	right = 0
	max_c = 0
	res = 0
	while right < L:
		if isConsonant(name[right]):
			max_c += 1
		else:
			max_c = 0
		if max_c == n:
			while left <= right - n + 1:
				res += (L - right)
				left+= 1
			max_c -= 1
		right += 1
	print 'Case #%d: %d' % (case_no, res)
