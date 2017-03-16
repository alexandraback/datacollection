import sys
lines=sys.stdin.readlines();
n=int(lines[0])
for case in range(1, n+1):
	cakes=lines[case].strip()
	dp=[ [0,0] ] *  (len(cakes)+1)
	for i in range(1, len(cakes)+1):
		m=i-1
		while m>0 and cakes[m-1]==cakes[i-1]:
			m=m-1
		if cakes[i-1]=='+':
			dp[i][0]=dp[m][0]
			dp[i][1]=dp[m][0]+1
		else:
			dp[i][0]=dp[m][1]+1
			dp[i][1]=dp[m][1]
	print "Case #%d: %d" % (case, dp[i][0])
			
			
		


