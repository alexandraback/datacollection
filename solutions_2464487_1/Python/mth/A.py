#!/usr/bin/env python

FILE_NAME_BASE = 'A-large'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	r, t = (int(x) for x in inp.readline().split())
	return r, t

def search(low, high, test):
	'''Binary search: [low..high) is the range to search; function "test"
	takes a single value from that interval and returns a truth value.
	The function must be ascending: (test(x) and y >= x) => test(y).
	Returns smallest argument in the interval for which the function is true,
	or "high" if the function is false for the entire interval.
	'''
	while low < high:
		mid = (low + high - 1) / 2
		if test(mid):
			if mid == low:
				return low # found
			high = mid + 1
		else:
			low = mid + 1
	return high # not found

def solve(r, t):
	def impossible(i):
		return 2 * i * (i - 1) + i * (2 * r + 1) > t

	return search(0, 708000000, impossible) - 1

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
