T = input()
for t in range(T):
	N,M = map(int, raw_input().split())
	a = []
	for i in range(N):
		a.append(map(int, raw_input().split()))
	ans = 0
	for i in range(N):
		for j in range(M):
			x = max(a[i][k] for k in range(M))
			y = max(a[k][j] for k in range(N))
			if a[i][j] != x and a[i][j] != y:
				ans = 1
	print "Case #" + str(t+1) + ": " + ["YES", "NO"][ans]
