filename = 'C-small-attempt1 (1).in'
f = open(filename,'r')
T = int(f.readline())
for i in range(1,T+1):
	print "Case #%d:" % i,
	J,P,S,K = map(int,f.readline().rstrip().split())
	jp = dict()
	ps = dict()
	js = dict()
	ans = list()
	for j in range(1,J+1):
		for p in range(1,P+1):
			for s in range(1,S+1):
				if jp.get((j,p),0) < K and ps.get((p,s),0) < K and js.get((j,s),0) < K:
					ans.append([j,p,s])
					try:
						jp[j,p] += 1
					except KeyError:
						jp[j,p] = 1
					try:
						ps[p,s] += 1
					except KeyError:
						ps[p,s] = 1
					try:
						js[j,s] += 1
					except KeyError:
						js[j,s] = 1


	if K < 3 and J*P*min(S,K) != len(ans):
		if (J,P,S,K) == (3,3,3,1):
			ans = [[1,1,1],[1,2,2],[1,3,3],[2,1,2],[2,2,3],[2,3,1],[3,1,3],[3,2,1],[3,3,2]]
		if (J,P,S,K) == (3,3,3,2):
			ans = [[1,1,2],[1,1,3],[1,2,1],[1,2,3],[1,3,1],[1,3,2],
			[2,1,1],[2,1,3],[2,2,1],[2,2,2],[2,3,2],[2,3,3],
			[3,1,1],[3,1,2],[3,2,2],[3,2,3],[3,3,1],[3,3,3]]
		if (J,P,S,K) == (1,3,3,2):
			ans = [[1,1,1],[1,1,2],[1,2,1],[1,2,3],[1,3,2],[1,3,3]]
		if (J,P,S,K) == (2,3,3,1):
			ans = [[1,1,1],[1,2,2],[1,3,3],[2,1,2],[2,2,3],[2,3,1]]
		if (J,P,S,K) == (2,3,3,2):
			ans = [[1,1,2],[1,1,3],[1,2,1],[1,2,3],[1,3,1],[1,3,2],
			[2,1,1],[2,1,3],[2,2,1],[2,2,2],[2,3,2],[2,3,3]]



	print len(ans)
	for i in ans:
		for j in i:
			print j,
		print
