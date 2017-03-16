import sys

filename = sys.argv[1]

with open(filename, 'r') as fh:
	T = int(fh.readline().strip())
	for t in range(T):
		K, C, S = map(int, fh.readline().strip().split(' '))
		print "Case #%d: %s" % (t+1, ' '.join(
			map(lambda x: str(x), range(1, K+1))))