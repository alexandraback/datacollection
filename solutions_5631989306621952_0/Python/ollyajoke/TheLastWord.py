def findLastWord(s):
	res = [s[0]]
	for i in xrange(1, len(s)):
		if s[i] >= res[0]:
			res.insert(0, s[i])
		else:
			res.append(s[i])
	return "".join(res)


T = int(raw_input().strip())
for i in range(0,T):
	S = raw_input().strip()
	print "Case #" + str(i+1) + ':', findLastWord(S)