n=int(raw_input())
import sys
import math

TOT = 0
S = 0
LL = 0
RR = 0

dp = [[]]

def f(L,R):
	# print 'LR is',L,R
	# print TOT
	if (dp[L][R]!=-1):
		return dp[L][R]
	dp[L][R]=0
	if (L+R==TOT):
		dp[L][R]=1
		return dp[L][R]
	if (R==S and L==S):
		dp[L][R]=f(L+1,R)
		return dp[L][R]
	if (R==S):
		dp[L][R]=f(L+1,R)
		return dp[L][R]
	if (L==S):
		dp[L][R]=f(L,R+1)
		return dp[L][R]
	dp[L][R]=f(L,R+1)+f(L+1,R)
	return dp[L][R]

def f2(L,R):
	if (dp[L][R]!=-1):
		return dp[L][R]
	dp[L][R]=0
	# print 'LRTOT',L,R
	if (L+R==TOT):
		if (R>=RR): dp[L][R]=1
		return dp[L][R]
	if (R==S and L==S):
		dp[L][R]=f2(L+1,R)
		return dp[L][R]
	if (R==S):
		dp[L][R]=f2(L+1,R)
		return dp[L][R]
	if (L==S):
		dp[L][R]=f2(L,R+1)
		return dp[L][R]
	dp[L][R]=f2(L,R+1)+f2(L+1,R)
	return dp[L][R]

for tc in xrange(1,n+1):
	N,x,y = map(int,raw_input().split());
	nx=abs(x)
	ny=abs(y)
	if (N==1):
		if (x==0 and y==0):
			hihu='Case #'
			hihu+=str(tc)
			hihu+=': 1.00'
			print hihu
		else:
			hihu='Case #'
			hihu+=str(tc)
			hihu+=': 0.00'
			print hihu
		continue

	bates=0
	while (bates*(2*bates-1)<N): bates+=1
	# print 'ha',bates*(2*bates-1)
	# print N
	if (bates*(2*bates-1)==N):
		hihu='Case #'
		hihu+=str(tc)
		hihu+=': 1.00'
		print hihu
		continue
	# continue

	# print 'Bates is',bates
	bates-=1
	TOT = N-bates*(2*bates-1)
	# print 'N is',N
	bates+=1
	# print TOT
	S=(bates-1)*2
	sm=(bates-1)*2
	# print 'S is',S
	# print 'SUM',nx+ny
	# print 'SUM',sm
	if (nx+ny<sm):
		hihu='Case #'
		hihu+=str(tc)
		hihu+=': 1.00'
		print hihu
		continue
	if (nx+ny!=sm):
		hihu='Case #'
		hihu+=str(tc)
		hihu+=': 0.00'
		print hihu
		continue
	dp = [[-1 for i in xrange(2000)] for j in xrange(2000)]
	RR = ny+1
	LL = TOT-RR
	total = f(0,0)
	dp = [[-1 for i in xrange(2000)] for j in xrange(2000)]
	used = f2(0,0)
	# print 'Total USED',total,used
	ans = 1.000*used/(1.00*total)
	hihu='Case #'
	hihu+=str(tc)
	hihu+=': '
	hihu+=str(round(ans,10))
	print hihu
