dp = [int(x) for x in range(1000005)]

def invert(n):
	return int(str(n)[::-1])

for i in range(1,1000000):
	if dp[i+1] > dp[i]+1:
		dp[i+1] = dp[i]+1
	if dp[invert(i)] > dp[i]+1:
		dp[invert(i)] = dp[i]+1

T=int(input())
for tc in range(1,T+1):
	N=int(input())
	print('Case #{_tc}: {_sol}'.format(_tc=tc, _sol=dp[N]))
