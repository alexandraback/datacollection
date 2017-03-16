#!/usr/bin/env python

FILE_NAME_BASE = 'A-small-attempt0'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	n = int(inp.readline())
	return n,

def solve(n):
	#print '->', n
	ndigits = len(str(n))
	digits = 1
	c = 1
	i = 1

	while True:
		assert c == 10 ** (digits - 1), (c, digits)
		if c == n:
			#print
			return i

		if digits < ndigits:
			target = 10 ** digits - 1
		elif n % 10 == 0:
			target = n - 1
		else:
			target = n

		if digits == 1:
			i += target - c
			c = target
		else:
			frontStr = str(target)[:digits / 2]
			front = int(frontStr)
			back = int(''.join(reversed(list(frontStr))))

			i += back
			c += back
			if back != 1:
				i += 1
				c = int(''.join(reversed(list(str(c)))))
			i += target - c
			c = target

			#print front, back, target

			i += target - c
			c = target

		if digits < ndigits:
			c += 1
			i += 1
			digits += 1
		else:
			if n % 10 == 0:
				i += 1
				c += 1
			assert c == n, (c, n)
			#print
			return i

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
