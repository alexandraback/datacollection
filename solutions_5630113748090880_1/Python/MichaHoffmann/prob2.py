import itertools

def solve(lists):
	merged = list(itertools.chain.from_iterable(lists))
	menge = list(set(merged))
	solution = []
	for k in menge: 
		if merged.count(k)%2 == 1:
			solution.append(k)
	strsolution = [str(k) for k in sorted(solution)]
	return " ".join(strsolution)



t = int(raw_input())
for i in xrange(1, t+1):
	N = int(raw_input())
	lists = []
	for j in xrange(1, 2*N):	
		lists.append([int(k) for k in raw_input().split(" ")])
	print "Case #{}: {}".format(i, solve(lists))
