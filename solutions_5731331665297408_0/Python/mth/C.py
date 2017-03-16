#!/usr/bin/env python

FILE_NAME_BASE = 'C-small-attempt0'
NUM_PROCESSES = 4
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	numCities, numFlights = (int(x) for x in inp.readline().split())
	zipcodes = tuple(inp.readline().strip() for _ in xrange(numCities))
	flights = tuple(
		tuple(int(x) - 1 for x in inp.readline().split())
		for _ in xrange(numFlights)
		)
	return zipcodes, flights

def solve(zipcodes, flights):
	numCities = len(zipcodes)
	
	dest = [[] for _ in xrange(numCities)]
	for i, j in flights:
		dest[i].append(j)
		dest[j].append(i)
	dest.append(range(numCities))

	bestzips = [None]
	def rec(stack, zips, toVisit):
		if toVisit == 0:
			if bestzips[0] is None or zips < bestzips:
				bestzips[:] = zips
		elif stack:
			city = stack[-1]
			for d in dest[city]:
				if ((1 << d) & toVisit) != 0:
					rec(stack + [d],
						zips + [zipcodes[d]],
						toVisit & ~(1 << d))
			if len(stack) > 2:
				rec(stack[ : -1], zips, toVisit)

	rec([numCities], [], (1 << numCities) - 1)

	return ''.join(bestzips)

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
