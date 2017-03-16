T = input()
for t in range(T):
	A,N = map(int, raw_input().split())
	a = sorted(map(int, raw_input().split()))
	if A == 1:
		print "Case #" + str(t+1) + ":", N
		continue
	ans = len(a)
	tmp = 0
	for i in range(N):
		ans = min(ans, tmp+N-i)
		while A <= a[i]:
			A = A+A-1
			tmp += 1
		A += a[i]
	print "Case #" + str(t+1) + ":", min(tmp, ans)
