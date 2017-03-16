T = input()
for _ in xrange(T):
	r,c,w = map(int,raw_input().split())
	ans = 0
	if w == 1:
		ans = r * c
	elif r == 1:
		ans = c/w + w
		if c % w == 0:
			ans -= 1
	elif c == 1:
		ans = r/w + w
		if r % w == 0:
			ans -= 1
	else:
		for i in xrange(r-1):
			ans += c/w
			if c % w != 0 and (i+1) % w == 0:
				ans += 1
		if c % w == 0:
			ans += c/w + w
		else:
			ans += c/w + w + 1
	print "Case #%d: %d" % (_+1,ans)