from collections import Counter

def iterator(N, M, lower=2):
	if N == 1:
		for i in xrange(lower, M+1):
			yield (i,)
	else:
		for aux in iterator(N-1, M, lower):
			for i in xrange(lower, M+1):
				yield (i,) + aux

T = int(raw_input())

print 'Case #1:'

for t in xrange(T):
	R, N, M, K = map(int, raw_input().split())
	probofproduct = Counter()
	for nlist in iterator(N, M):
		for subset in iterator(N, 1, 0):
			product = 1
			for i in xrange(N):
				if subset[i] == 1:
					product *= nlist[i]
			probofproduct[(nlist, product)] += 1
	for r in xrange(R):
		maxprob = 0
		maxlist = None
		products = map(int, raw_input().split())
		for nlist in iterator(N, M):
			prob = 1
			for p in products:
				prob *= probofproduct[(nlist, p)]
			if prob >= maxprob:
				maxprob = prob
				maxlist = nlist
		print ('%d'*N) % maxlist
