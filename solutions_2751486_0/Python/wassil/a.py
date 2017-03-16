def hasNCon(s,n):
	j=0
	for i in range(len(s)):
		if not (s[i] in ["a","e","i","o","u"]):
			j+=1
		else:
			j=0
		if j==n:
	#		print s
			return True
	return False
for T in range(int(raw_input())):
	data = raw_input().split()
	s = data[0]
	n = int(data[1])
	res = 0
	for i in range(len(s)):
			for j in range(i,len(s)):
				if hasNCon(s[i:j+1],n):
						res+=1
	print "Case #%d: %d"%(T+1,res)
