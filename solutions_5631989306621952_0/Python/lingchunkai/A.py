
def solve(s):


	# x = solve(s[1:len(s)])

	xx = s[0]
	for i in xrange(1,len(s)):
		if s[i] >= xx[0]:
			xx = s[i] + xx
		else:
			xx = xx + s[i]

	return xx

T = int(raw_input())
for t in xrange(T):
	S = raw_input()
	

	print "Case #" + str(int(t+1)) + ": " +solve(S)