t = int(input())
for cas in range(t):
	(n, a) = list(input().split())
	s = 0
	ans = 0
	for i in range(len(a)):
		b = ord(a[i]) - ord('0')
		ans = max(ans, i - s)
		s += b
	print('Case #%d: %d' % (cas+1, ans))
