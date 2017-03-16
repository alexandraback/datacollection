f = open("1.in")
n = int(f.readline()[:-1])
s_list = f.readlines()
for test_num, s in zip(range(1, n+1), s_list):
	s = s[:-1]
	ans = ""
	for c in s:
		if ans == "":
			ans = c
			continue
		if c >= ans[0]:
			ans = c + ans
		else:
			ans = ans + c
	

	print "Case #%d: %s" % (test_num, ans)
