t = int(raw_input())

for i in range(1, t+1):
	s = raw_input()
	ans = s[0]
	for c in s[1:]:
		if(c >= ans[0]):
			ans = c+ans
		else:
			ans = ans+c
	print "Case #" + str(i) + ": " + ans
