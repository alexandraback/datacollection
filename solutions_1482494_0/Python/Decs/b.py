tests = int(raw_input())
for test in xrange(1, tests + 1):
	n = int(raw_input())
	needed = [map(int, raw_input().split()) for i in xrange(n)]
	finishes = 0
	total = 0
	completed = [0] * n
	
	changed = True
	while changed:
		changed = False
		
		for level in xrange(n):
			if completed[level] < 2 and total >= needed[level][1]:
				finishes += 1
				total += 2 - completed[level]
				completed[level] = 2
				changed = True
				break
		
		if changed:
			continue
		
		one_star = [(-needed[i][1], i) for i in xrange(n) if completed[i] == 0 and total >= needed[i][0]]
		one_star.sort()
		if len(one_star) >= 1:
			finishes += 1
			total += 1
			completed[one_star[0][1]] = 1
			changed = True
	
	if total != 2 * n:
		print 'Case #%d: Too Bad' % test
	else:
		print 'Case #%d: %d' % (test, finishes)