for t in xrange(int(raw_input())):
	s = raw_input()
	ans = s[0]
	for c in s[1:]:
		if (c>=ans[0]):
			ans = c+ans
		else:
			ans = ans+c
	print "Case #"+str(t+1)+": "+str(ans)
