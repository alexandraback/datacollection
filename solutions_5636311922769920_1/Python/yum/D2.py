import itertools

TC = int(input())
for tc in range(TC):
	K, C, S = map(int, input().split())
	C = min(C, K)
	N = (K+C-1) // C
	if N > S:
		print("Case #%d: IMPOSSIBLE" % (tc+1))
		continue
	ans = []
	for n in range(N):
		p = [x % K for x in range(n*C, n*C+C)]
		ans.append(sum(x*K**(C-i-1) for i, x in enumerate(p)))
	print("Case #%d: %s" % (tc+1, ' '.join(str(x+1) for x in ans)))
