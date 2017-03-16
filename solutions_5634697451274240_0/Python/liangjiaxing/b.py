re = int(raw_input())

for cas in range(re):
	print "Case #%d:" % (cas + 1),
	s = raw_input().strip()
	l = s[0]
	ans = 0
	for i in s[1:]:
		if i != l:
			ans += 1
			l = i
	if l == '-':
		ans += 1
	print ans

