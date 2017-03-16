T = int(raw_input())
for t in xrange(T):
	s = raw_input()
	p = 0
	for i in xrange(1,len(s)):
		if not s[i] == s[i-1]:
			p += 1
	if s[len(s)-1] == '-':
		p+=1
	print "Case #" + str(t+1) + ": " + str(p)