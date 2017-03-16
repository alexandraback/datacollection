import sys
f = open(sys.argv[1], 'r')
T = int(f.readline().split()[0])

for t in xrange(T):
	A, N = [int(x) for x in f.readline().split()]
	list_motes = [int(x) for x in f.readline().split()]

	list_motes = sorted(list_motes)
	best_cost = N
	if A == 1:
		pass
	else:
		for i in xrange(N+1):
			cost = N - i
			shit = A
			for j in xrange(0, i):
				while shit <= list_motes[j]:
					cost += 1
					shit = 2*shit - 1
				shit += list_motes[j]
			best_cost = min(best_cost, cost)

	print "Case #%d: %d" % (t+1, best_cost)