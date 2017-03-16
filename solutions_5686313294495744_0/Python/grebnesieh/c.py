for case in xrange(1, input() + 1):
	n = input()
	papers = []
	for _ in xrange(n):
		papers.append(raw_input().split())
	ans = 0
	for j in xrange(2 ** n):
		first, second = set(), set()
		cnt = 0
		for i, x in enumerate(map(int, bin(j)[2:].zfill(n))):
			if x:
				first.add(papers[i][0])
				second.add(papers[i][1])
			else:
				cnt += 1
		for x, y in papers:
			if x not in first or y not in second:
				break
		else:
			ans = max(ans, cnt)
	print "Case #" + str(case) + ": " + str(ans)