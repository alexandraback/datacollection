#!/usr/bin/env python

FILE_NAME_BASE = 'B-large'
NUM_PROCESSES = 4
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	numPlates = int(inp.readline())
	plates = tuple(int(x) for x in inp.readline().split())
	assert len(plates) == numPlates
	return plates,

def solve(plates):
	# Observations:
	# - since there are an infinite number of plates, it is optimal to always
	#   split a pancake stack onto an empty plate
	# - it is optimal to put all the special (split) minutes at the start,
	#   since the eating rate is equal to the number of non-empty plates
	# - time spent is number of splits + maximum stack size over all plates
	# - if you decide to not split the highest stack, there is no point in
	#   splitting any other stack

	# How high is the highest pancake stack?
	maxStack = max(plates)

	best = maxStack # takes this long if we don't split
	for target in xrange(2, maxStack):
		# How many times do we have to split to not be over target?
		splits = 0
		for plate in plates:
			splits += (plate - 1) / target
		best = min(best, target + splits)

	return best

def main():
	import sys
	sys.setrecursionlimit(RECURSION_LIMIT)

	import resource
	soft, hard = resource.getrlimit(resource.RLIMIT_AS)
	resource.setrlimit(resource.RLIMIT_AS, (MEM_LIMIT_GB * 1024 ** 3, hard))

	inp = open(FILE_NAME_BASE + '.in', 'r')
	numCases = int(inp.readline())
	if NUM_PROCESSES == 0:
		results = [
			solve(*parse(inp))
			for _ in range(numCases)
			]
	else:
		from multiprocessing import Pool
		pool = Pool(NUM_PROCESSES)
		results = [
			pool.apply_async(solve, parse(inp))
			for _ in range(numCases)
			]
	inp.close()
	out = open(FILE_NAME_BASE + '.out', 'w')
	for case, result in enumerate(results):
		value = result if NUM_PROCESSES == 0 else result.get()
		out.write('Case #%d: %s\n' % (case + 1, value))
		out.flush()
	out.close()

if __name__ == '__main__':
	main()
