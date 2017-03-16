import fileinput
import sys
from collections import Counter


def main():
	stream = fileinput.input()
	cases = int(next(stream))
	for case in xrange(cases):
		edges = Counter()
		paths_c = 0
		buildings, paths = map(int, next(stream).strip().split(' '))
		for bpair in zip(range(buildings), range(buildings)[1:]):
			edges[bpair] += 1
		paths_c += 1

		for i in xrange(0, buildings):
			for j in xrange(i + 1, buildings):
				if (i, j) not in edges:
					paths_c += 1
					edges[(i, j)] += 1
					if paths_c >= paths:
						break
			if paths_c >= paths:
				break

		if paths_c == paths:
			print "Case #%d: %s" % (case + 1, 'POSSIBLE')
			for i in xrange(0, buildings):
				for j in xrange(0, buildings):
					if (i, j) in edges:
						sys.stdout.write('1')
					else:
						sys.stdout.write('0')
				sys.stdout.write('\n')
				sys.stdout.flush()
		else:
			print "Case #%d: %s" % (case + 1, 'IMPOSSIBLE')


if __name__ == '__main__':
	main()
