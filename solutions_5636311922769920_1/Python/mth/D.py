#!/usr/bin/env python

FILE_NAME_BASE = 'D-large'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	k, c, s = (int(x) for x in inp.readline().split())
	return k, c, s

def solve(numTiles, complexity, numStudents):
	if numStudents * complexity < numTiles:
		return 'IMPOSSIBLE'

	result = []
	pos = 0
	while pos < numTiles:
		# Coordinates to inspect.
		coord = range(pos, min(pos + complexity, numTiles))
		coord += [0] * (complexity - len(coord))
		assert len(coord) == complexity
		pos += complexity

		# Convert to linear.
		result.append(sum(x * numTiles ** i for i, x in enumerate(coord)))

	return ' '.join(str(tile + 1) for tile in result)

def main():
	import sys
	sys.setrecursionlimit(RECURSION_LIMIT)

	import resource
	soft, hard = resource.getrlimit(resource.RLIMIT_AS)
	resource.setrlimit(resource.RLIMIT_AS, (MEM_LIMIT_GB * 1024 ** 3, hard))

	with open(FILE_NAME_BASE + '.in', 'r') as inp:
		numCases = int(inp.readline())
		inputs = [parse(inp) for _ in xrange(numCases)]

	if NUM_PROCESSES == 0:
		runners = [lambda inp=inp: apply(solve, inp) for inp in inputs]
	else:
		from multiprocessing import Pool
		from signal import SIGINT, SIG_IGN, signal
		pool = Pool(NUM_PROCESSES, signal, (SIGINT, SIG_IGN))
		runners = [pool.apply_async(solve, inp).get for inp in inputs]
		pool.close()

	caseFmt = '%' + str(len(str(numCases))) + 'd'
	progressFmt = '[%s/%s] %%s\n' % (caseFmt, caseFmt)
	with open(FILE_NAME_BASE + '.out', 'w') as out:
		for case, runner in enumerate(runners, 1):
			result = runner()
			out.write('Case #%d: %s\n' % (case, result))
			out.flush()
			sys.stderr.write(progressFmt % (case, numCases, result))

if __name__ == '__main__':
	main()
