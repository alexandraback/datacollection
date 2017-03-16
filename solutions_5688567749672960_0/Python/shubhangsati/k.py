def rev(a):
	return int(`a`[::-1])
dp=[-1]*(10**6+5)
dp[0]=0
for i in range(1,11):
	dp[i]=dp[i-1]+1
for i in range(11,10**6+1):
	x=rev(i)
	if x!=i and dp[x]!=-1 and i%10!=0:
		dp[i]=min(dp[i-1]+1,dp[x]+1)
	else:
		dp[i]=dp[i-1]+1
t=input()
for i in range(1,t+1):
	n=input()
	print "Case #"+`i`+": "+`dp[n]`
