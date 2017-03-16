import sys

def solve(i):
	N = int(sys.stdin.readline())
	digs = set(list(str(N)))
	if N == 0:
		print 'INSOMNIA'
	else:
		i = N
		while len(digs) < 10:
			i += N
			digs = digs.union(set(list(str(i))))
		print i


if __name__ == '__main__':
	c = int(sys.stdin.readline())
	for i in range(c):
		sys.stdout.write('Case #%d: ' % (i+1,))
		solve(i)
