for t in xrange(1, input() + 1):
	K, C, S = map(int, raw_input().split())
	print "Case #" + str(t) + ":",
	checked = 0
	cnt = 0
	ans = []
	while checked < K:
		cnt += 1
		checked += 1
		i = checked
		for j in xrange(C - 1):
			if checked < K:
				i = K * (i - 1)
				checked += 1
				i += checked
			else:
				i = K * (i - 1) + 1
		ans.append(i)
	if len(ans) <= S:
		for x in ans:
			print x,
		print
	else:
		print "IMPOSSIBLE"