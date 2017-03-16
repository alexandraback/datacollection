import sys

def solve(i):
	K, C, S = map(int, sys.stdin.readline().split())
	if S < (K + C - 1) / C:
		print 'IMPOSSIBLE'
	else:
		ret = []
		for i in xrange(0, K, C):
			idx = i
			#sys.stderr.write('Looking at %d\n' % (idx))
			for k in xrange(1, C):
				if k + i >= K:
					idx = idx * K
					#sys.stderr.write('All done, moved to %d\n' % (idx))
				else:
					idx = idx * K + k + i
					#sys.stderr.write('Also looking at %d, moved to %d\n' % (k + i, idx))
			ret.append(idx + 1)
		print ' '.join(map(str, ret))

if __name__ == '__main__':
	c = int(sys.stdin.readline())
	for i in range(c):
		sys.stdout.write('Case #%d: ' % (i+1,))
		solve(i)
