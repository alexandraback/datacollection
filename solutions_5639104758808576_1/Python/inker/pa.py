for case_no in range(int(raw_input())):
	_, s = raw_input().split()
	
	for idx, char in reversed(list(enumerate(s))):
		if char != "0":
			last_not_of_0 = idx
			break
	else:
		last_not_of_0 = -1
	
	s = s[:last_not_of_0+1]

	ans = 0
	cur = 0
	for idx, val in enumerate(s):
		ans += max(0, idx-(cur+ans))
		cur += ord(val) - ord("0")
		#print "ans %d cur %d" % (ans, cur)
	
	print "Case #%d: %d" % (case_no+1, ans)
