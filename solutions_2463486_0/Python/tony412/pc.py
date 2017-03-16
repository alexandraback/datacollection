#!/usr/bin/env python

t = int(raw_input())

for c in range(1, t+1):
	a, b = raw_input().split(" ")
	a = int(a)
	b = int(b)

	ans = 0
	i = 1
	while i * i < a:
		i += 1
	while i * i <= b:
		s = str(i)
		if s == s[::-1]:
			s = str(i * i)
			if s == s[::-1]:
				ans += 1
		i += 1

	print "Case #%d: %d" % (c, ans)
	
