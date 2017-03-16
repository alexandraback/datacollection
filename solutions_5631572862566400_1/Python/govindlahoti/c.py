t = input()

for q in xrange(1, t+1):
	n = input()
	bff = [0] + map(int, raw_input().split())
	pcircles = []
	loose = []
	loose_lens = []
	for s in xrange(1, n+1):
		temp = [s]
		isin = [0 for _ in xrange(n+1)]
		isin[s] = 1
		while isin[bff[temp[-1]]] == False:
			isin[bff[temp[-1]]] = 1
			temp.append(bff[temp[-1]])
		if bff[temp[-1]] == s and len(temp)>2:
			pcircles.append(temp)
		elif bff[temp[-1]] != temp[-2]:
			continue
		else:
			loose.append(temp)

	while len(loose)>0:
		ll = loose[0]
		cand = [i for i in loose if i[-1] == ll[-2]]
		cand2 = [i for i in loose if i[-1] == ll[-1]]
		cand_len = [len(i) for i in cand]
		cand2_len = [len(i) for i in cand2]
		# print cand
		# print cand2
		# print ll
		loose_lens.append(max(cand_len) + max(cand2_len) - 2)
		for i in cand:
			loose.remove(i)
		for i in cand2:
			loose.remove(i)

	ans = 0
	if len(pcircles) > 0:
		ans = max([len(i) for i in pcircles])

	ans = max(ans, sum(loose_lens))	
	print 'Case #{}: {}'.format(q, ans)