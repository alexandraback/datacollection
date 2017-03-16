getl = lambda: raw_input().split()
get = lambda: map(int, getl())

T, = get()

for testCase in range(1, T+1):
	_, = get()
	P = get()
	limit = max(P)
	best = limit
	for left in range(1, limit + 1):
		swaps = sum((p-1) / left for p in P)
		best = min(best, left + swaps)
	print "Case #%d: %d" % (testCase, best)
