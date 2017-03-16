for i in xrange(1,input()+1):
	S=raw_input()
	s=S[0]
	for j in S[1:]:
		if j>=s[0]:
			s=j+s
		else:
			s=s+j





	print "Case #{}: {}".format(i,s)