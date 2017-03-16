def recurs(t,seq,k):
	if len(seq) == N:
		print("Case #%d:" % w,' '.join([str(i+1) for i in seq]))
		return True
	if tuple(set(seq)) in hist:
		return False
	hist.add(tuple(set(seq)))
	for i in range(len(t)):
		if t[i][1] in k:
			x = k.index(t[i][1])
			if recurs(t[:i]+t[i+1:],seq+[t[i][0]],k[:x]+k[x+1:]+c[t[i][0]]):
				return True
	else:
		return False

T=int(input())
for w in range(1,T+1):
	hist = set()
	K,N = (int(i) for i in input().split())
	k = [int(i) for i in input().split()]
	c = []
	t = []
	for j in range(N):
		line = [int(i) for i in input().split()]
		t.append((j,line.pop(0)))
		line.pop(0)
		c.append(line)
	k.sort()
	for i in range(N):
		if t[i][1] in k:
			x = k.index(t[i][1])
			if recurs(t[:i]+t[i+1:],[t[i][0]],k[:x]+k[x+1:]+c[t[i][0]]):
				break
	else:
		print("Case #%d:" % w,'IMPOSSIBLE')
