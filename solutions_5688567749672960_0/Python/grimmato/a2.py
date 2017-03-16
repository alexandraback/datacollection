MAXN = 10**6 + 2
dp = [0 for i in xrange(MAXN)]
for i in xrange(0,11):
	dp[i] = i
for i in xrange(11,MAXN):
	s = str(i)
	rev = s[::-1]
	x = 10**19
	if s[len(s)-1] != '0' and int(rev) < i:
		x = dp[int(rev)] + 1
		dp[i] = min(dp[i-1] + 1, x)
	else:
		x = dp[i-1] + 1
		dp[i] = min(dp[i-1] + 1, x)



t=int(raw_input())
for qq in xrange(t):
	n = int(raw_input())
	print 'Case #{0}: {1}'.format(qq+1,dp[n])
