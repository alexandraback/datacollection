def longest_back(BFF, BACK_ADJ, cur, excl):
	best = 0
	for x in BACK_ADJ[cur]:
		if x == excl: continue
		best = max(best, longest_back(BFF, BACK_ADJ, x, None))
	return best+1

T = int(raw_input())
for t in xrange(T):
	n = int(raw_input())
	S = raw_input()
	BFF = map(int, S.split())
	BFF = [x-1 for x in BFF];
	BACK_ADJ =  [[] for x in xrange(n)]
	for i, v in enumerate(BFF):
		BACK_ADJ[v].append(i)

	

	# find all 2-cycles
	pom = []
	visited = n * [False]
	for a in xrange(n):
		if visited[a]: continue
		if a == BFF[BFF[a]]:
			pom.append((a, BFF[a]))
			visited[BFF[a]] = True
			

	total = 0
	# print len(pom)
	
	for p in pom:
		strength = longest_back(BFF, BACK_ADJ, p[0], p[1]) + longest_back(BFF, BACK_ADJ, p[1], p[0])
		#print longest_back(BFF, BACK_ADJ, p[0], p[1]), longest_back(BFF, BACK_ADJ, p[1], p[0])
		total += strength
		#print pom

	# case of cycle
	visited = n * [False]
	longest = 0
	for i in xrange(n):
		if visited[i]: continue
		k = i;
		z = 0
		ok = True
		while (not BFF[k] == i):
			if visited[k] == True: 
				ok = False
				break
			visited[k] = True
			k = BFF[k]
			z+=1
		if ok == True:
			longest = max(longest,z+1)

	print "Case #" + str(int(t+1)) + ": " + str(max(total, longest))