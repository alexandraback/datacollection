def dfs(n,m,i,edges,zipcode,v,vu):
	if (len(vu)==n):
		return vu
	elif (i > 2*m):
		return None

	s = v[-1]
	res = None
	for t in zipcode:
		reachable = False
		for visited in vu:
			reachable = reachable or t[1] in edges[visited]

		if (reachable and t[1] not in vu):
			temp = dfs(n,m,i+1,edges,zipcode,v+[t[1]],vu+[t[1]])
			if temp:
				if not res:
					res = temp
				else:
					good = True
					for i in xrange(len(res)):
						if temp[i] > res[i]:
							good = False
							break
					if good: res = temp

	return res

with open('C-small-attempt1.in') as f:
	T = int(f.readline())

	for case in xrange(T):
		data = [int(x) for x in f.readline().split()]

		n = data[0]; m = data[1]

		zipcode = []
		for i in range(n):
			zipcode += [int(f.readline())]

		edges = []
		for i in range(m):
			edges += [[int(x) for x in f.readline().split()]]

		edgelist = [set() for x in range(n)]
		for t in edges:
			a = t[0]-1; b = t[1]-1
			edgelist[a].add(b)
			edgelist[b].add(a)

		zipcode = zip(zipcode, range(n))
		zipcode = sorted(zipcode, key=lambda x:x[0])
		
		for t in zipcode:
			temp = dfs(n,m,0,edgelist,zipcode,[t[1]],[t[1]])
			if temp:
				s = ""
				for x in temp:
					for tup in zipcode:
						if (tup[1] == x):
							s += str(tup[0])
							break

				print "Case #%d: %s" % (case+1,s)
				break