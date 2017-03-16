T = int(raw_input())

for test in xrange(T):
	S_max, people = raw_input().split()
	S_max = int(S_max)
	people = [int(i) for i in people]
	ans = 0
	tot = 0
	for i, num in enumerate(people):
		if tot < i:
			ans += i - tot
			tot += i - tot
		tot += num
	print "Case #{}: {}".format(test + 1, ans)