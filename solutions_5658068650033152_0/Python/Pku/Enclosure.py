T = int(raw_input())

results = []

for k in xrange(T):
	N, M, K = map(int, raw_input().split())
	stonesToAdd = max(0, 4+K-N*M)
	possibles = [K]
	for i in xrange(1,N-1):
		for j in xrange(1,M-1):
			enclosed = 2*i+2*j+i*j
			if enclosed >= K:
				possibles.append(2*i+2*j)
	result = min(possibles)+stonesToAdd
	results.append(result)

"""
for k in xrange(T):
	print "Case #{}: {}".format(k+1, results[k])

"""
f = open("EnclosureOut.txt", 'w')
for k in xrange(T):
	print >> f, "Case #{}: {}".format(k+1, results[k])
f.close()

