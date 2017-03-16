#!/usr/bin/env python

FILE_NAME_BASE = 'B-small-attempt0'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	n, = (int(x) for x in inp.readline().split())
	lists = tuple(
		tuple(int(x) for x in inp.readline().split())
		for _ in xrange(2 * n - 1)
		)
	return n, lists

def subsets(sequence):
	'''Iterates through all subsets of the given sequence.
	Each yielded element is a tuple containing a subset of the elements of
	the original sequence, in the same order as in the original sequence.
	'''
	sequence = tuple(sequence)
	size = len(sequence)
	def rec(s, i):
		if i == size:
			yield tuple(s)
		else:
			s.append(sequence[i])
			for sub in rec(s, i + 1):
				yield sub
			del s[-1]
			for sub in rec(s, i + 1):
				yield sub
	return rec([], 0)

def solve(n, lists):
	for rows in subsets(lists):
		if len(rows) != n:
			continue
		rows = set(rows)
		if len(rows) != n:
			# Duplicate lists can exist, but duplicate rows make grid invalid.
			continue
		to_drop = set(rows)
		cols = set()
		for l in lists:
			if l in to_drop:
				to_drop.discard(l)
			else:
				cols.add(l)
		if len(cols) != n - 1:
			# Duplicate lists can exist, but duplicate cols make grid invalid.
			continue
		grid = tuple(sorted(rows))
		gridcols = set(
			tuple(grid[row][col] for row in xrange(n))
			for col in xrange(n)
			)
		overlap = gridcols & cols
		if len(overlap) != n - 1:
			continue
		diff = gridcols - cols
		assert len(diff) == 1, diff
		missing = diff.pop()
		break
	else:
		assert False
	return ' '.join(str(h) for h in missing)

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
