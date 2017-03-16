T = int(raw_input())

for test in xrange(T):
	D = int(raw_input())
	plates = [int(i) for i in raw_input().split()]
	ans = max(plates)
	for i in xrange(1, ans):
		val = i + sum((j - 1) // i for j in plates)
		if val < ans:
			ans = val
	print "Case #{}: {}".format(test + 1, ans)