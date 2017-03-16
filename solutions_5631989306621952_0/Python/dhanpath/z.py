import sys
sys.stdin = open( "in", "r" )
sys.stdout = open( "out", "w" )

for t in range(input()):
	print "Case #"+str(t+1)+":",
	s = raw_input()
	ans = s[:1]
	for i in range(1,len(s)):
		if ord(s[i]) >= ord(ans[0]) :
			ans = s[i] + ans
		else:
			ans += s[i]
	print ans