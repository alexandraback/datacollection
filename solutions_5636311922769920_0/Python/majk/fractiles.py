T=int(input())

for c in range(T):
	K,C,S = map(int,input().split())
	if S * C < K:
		print("Case #%d: IMPOSSIBLE" % (c+1))
	else:
		u = 0
		R = []
		for _ in range((K-1) // C + 1):
			t = 0
			for i in range(C):
				t = t * K + min(u+i,K-1)
			R.append(t+1)
			u += C	 
		print("Case #%d: %s" % (c+1, ' '.join(map(str,R))))
