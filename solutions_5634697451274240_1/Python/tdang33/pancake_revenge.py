T = int(raw_input())

for case in range(1, T+1):
	s = raw_input()
	ans = 0
	if (s != ''):
		temp_char = s[0]
		#print len(s)-1
		for i in range (1,len(s)):
			#print temp_char, s[i]
			if (s[i] != temp_char):
				ans += 1
				temp_char = s[i]
	if (s[len(s)-1] == '-'):
		ans += 1
	print "Case #{}: {}".format(case, ans)
