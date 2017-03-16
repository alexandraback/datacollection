for case in range(1, int(input())+1):
	(J,P,S,K) = list(map(int,input().split()))
	result=[]
	jp = [0 for k in range(J*P)]
	ps = [0 for k in range(P*S)]
	js = [0 for k in range(J*S)]
	for j in range(J):
		steps0 = None
		if (j % 2) == 0 :
			steps0 = (0,P,1)
		else:
			steps0 = (P-1,-1,-1)
		for p in range(steps0[0],steps0[1],steps0[2]):
			if jp[j*P+p] < K:
				steps1 = None
				if ((p + j) % 2) == 0 :
					steps1 = (0,S,1)
				else:
					steps1 = (S-1,-1,-1)
				for s in range(steps1[0],steps1[1],steps1[2]):
					if (jp[j*P+p] < K) and (ps[p*S+s] < K) and (js[j*S+s] < K):
						jp[j*P+p] += 1
						ps[p*S+s] += 1
						js[j*S+s] += 1
						result.append("%s %s %s" % (j+1, p+1, s+1))
	
	print("Case #%d: %d" % (case,len(result)))
	for r in result:
		print(r)

