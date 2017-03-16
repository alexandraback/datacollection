T = int(input())
for t in range(T):
	N = int(input())
	l = []
	for i in range(2*N-1):
		l += list(map(int,input().split()))
	lbis = [e for e in l if l.count(e) % 2 != 0]
	lbis  = sorted(lbis)
	lter = []
	for e in lbis:
		if not e in lter:
			lter.append(e)
	print("Case #{}: {}".format(t+1," ".join(list(map(str,lter)))))