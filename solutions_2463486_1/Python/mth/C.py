#!/usr/bin/env python

FILE_NAME_BASE = 'C-large-1'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

precalc_limit = 100000000000000

def parse(inp):
	a, b = (int(x) for x in inp.readline().split())
	assert a <= b
	assert b <= precalc_limit
	return a, b

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

def isFair(x):
	l1 = list(str(x))
	l2 = list(l1)
	l2.reverse()
	return l1 == l2

numbers = []
def precalc():
	rl = search(0, precalc_limit + 1, lambda x: x * x > precalc_limit)
	for r in xrange(1, rl + 1):
		if isFair(r) and isFair(r * r):
			numbers.append(r)
			print r

def solve(a, b):
	ia = search(0, len(numbers), lambda i: numbers[i] * numbers[i] >= a)
	ib = search(0, len(numbers), lambda i: numbers[i] * numbers[i] > b)
	return ib - ia

def main():
	import sys
	sys.setrecursionlimit(RECURSION_LIMIT)

	import resource
	soft, hard = resource.getrlimit(resource.RLIMIT_AS)
	resource.setrlimit(resource.RLIMIT_AS, (MEM_LIMIT_GB * 1024 ** 3, hard))

	precalc()

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
