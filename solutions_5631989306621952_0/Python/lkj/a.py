def solve(s):
	curr = s[0]
	for i in range(1, len(s)):
		if s[i] >= curr[0]:
			curr = s[i]+curr
		else:
			curr = curr+s[i]
	return curr


tc = int(input())
for t in range(1, tc+1):
	s = input()
	print('Case #%i: %s' % (t,solve(s)))
