for case_no in range(int(raw_input())):
	n = raw_input()
	s = map(int, raw_input().split())
	ans = mx = max(s)
	for i in range(1, mx):
		ans = min(ans, sum(map(lambda x: (x-1)/i, s))+i)
	
	print "Case #%d: %d" % (case_no+1, ans)
