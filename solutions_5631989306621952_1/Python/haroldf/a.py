
t = int(raw_input())
for case in xrange(1,t+1):
	string = raw_input()
	ans=''*len(string)
	ans = string[0]
	for s in string[1:]:
		if int(ord(s)) >= int(ord(ans[0])):
			ans = s+ans
		else:
			ans = ans+s
	#print ans
	#print type(ans)
	print "Case #%s: %s" % (case, ans)