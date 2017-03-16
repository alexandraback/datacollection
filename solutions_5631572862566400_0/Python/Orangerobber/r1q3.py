import sys

T = int(sys.stdin.readline().strip())

def best(j, i, current):
	if i == len(j):
		return len(current)
	mx = best(j,i+1,current)
	if len(intersect(j[i], current)) == 0:
		return max(mx, best(j, i+1, current+j[i]))
	else:
		return mx

def intersect(a, b):
    return list(set(a) & set(b))

for t in range(T):
	N = int(sys.stdin.readline().strip())
	F = [int(x)-1 for x in sys.stdin.readline().strip().split()]
	sc = []
	maxR = 0
	skip = []
	for i in range(N):
		if i in skip:
			continue
		ring = [i]
		while True:
			if F[ring[-1]] not in ring:
				ring.append(F[ring[-1]])
				continue
			if F[ring[-1]] == ring[0]:
				if len(ring) > maxR:
					maxR = len(ring)
					break
			if F[ring[-1]] == ring[-2]:
				sc.append(ring)
				break
			break
	sc = sorted(sc, key = len, reverse=True)
	newsc = list(sc)

	for i in range(len(sc)):
		for j in range(i+1,len(sc)):
			s1 = sc[i]
			s2 = sc[j]
			if len(intersect(s1,s2)) == 2:
				if s2[-1] == s1[-2] and s2[-2] == s1[-1]:
					newsc.append(s1 + list(reversed(s2[:-2])))
	newsc = sorted(newsc, key = len, reverse=True)


	# best = []
	# for s in newsc:
	# 	if len(intersect(s, best)) == 0:
	# 		best += s

	b = best(newsc, 0, [])

	print "Case #%d: %d"%(t+1,max(maxR, b))

