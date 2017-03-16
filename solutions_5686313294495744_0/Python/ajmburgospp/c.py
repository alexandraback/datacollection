T = int(raw_input())
for kei in xrange(1, T+1):
	n = int(raw_input())
	ct = 0
	vis = dict()
	def addword(w):
		global ct
		if w not in vis:
			vis[w] = ct
			ct += 1
	arr = []
	for i in xrange(n):
		x, y = raw_input().split()
		addword(x)
		addword(y)
		arr.append((vis[x],vis[y]))
	# print vis
	# print arr
	sarr = set(arr)
	s = 0
	for i in arr:
		for j in arr:
			if i == j: continue
			# print i, j, (i[0], j[1])
			if (i[0], j[1]) in sarr and (i[0], j[1]) not in [i, j]:
				s += 1
	print "Case #{}: {}".format(kei, s)
