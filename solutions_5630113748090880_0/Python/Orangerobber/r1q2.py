import sys

T = int(sys.stdin.readline().strip())


for t in range(T):
	N = int(sys.stdin.readline().strip())
	lines = []
	for n in range(2*N-1):
		lines += [int(x) for x in sys.stdin.readline().strip().split()]
	poss = sorted(set([x for x in lines if lines.count(x) %2 == 1]))
	print "Case #%d:"%(t+1),
	for p in poss:
		print p,
	print ""
