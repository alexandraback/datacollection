def war(naomi, ken):
	A, B = sorted(naomi), sorted(ken)
	res = 0
	for a in A:
		found = False
		for i, b in enumerate(B):
			if b > a:
				found = True
				del B[i]
				break
		if not found:
			res += 1
			del B[0]
	return res


def deceitfulWar(naomi, ken):
	A, B = sorted(naomi), sorted(ken)
	N = len(A)
	dp = [[0] * N for _ in range(N)]
	for i in range(N):
		dp[i][i] = 1 if A[N-1] > B[i] else 0
	for l in range(2, N+1):
		for i in range(N-l+1):
			j = i+l-1
			if A[N-l] < B[j]:
				dp[i][j] = max(dp[i][j], dp[i][j-1])
			else:
				dp[i][j] = max(dp[i][j], 1 + dp[i][j-1])
			if A[N-l] > B[i]:
				dp[i][j] = max(dp[i][j], 1 + dp[i+1][j])
			else:
				dp[i][j] = max(dp[i][j], dp[i+1][j])
	return dp[0][N-1]


T = int(input())
for tc in range(T):
	input()
	naomi = [float(x) for x in input().split()]
	ken = [float(x) for x in input().split()]
	print('Case #{}: {} {}'.format(tc+1, deceitfulWar(naomi, ken), war(naomi, ken)))