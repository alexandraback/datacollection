#!/usr/bin/env python

FILE_NAME_BASE = 'C-small-attempt0'
NUM_PROCESSES = 4

def parse(inp):
	numbers = tuple(int(x) for x in inp.readline().split())
	count = numbers[0]
	numbers = numbers[1 : ]
	assert len(numbers) == count
	return numbers,

def solve(numbers):

	count = len(numbers)

	set1 = []
	set2 = []
	def rec(total1, total2, i):
		if i < count:
			n = numbers[i]
			# Skip number.
			if rec(total1, total2, i + 1):
				return True
			# Add to set 1.
			if rec(total1 + n, total2, i + 1):
				set1.append(n)
				return True
			# Add to set 2.
			if rec(total1, total2 + n, i + 1):
				set2.append(n)
				return True
			return False
		else:
			return total1 == total2 and total1 != 0

	if rec(0, 0, 0):
		return ' '.join(str(x) for x in set1), ' '.join(str(x) for x in set2)

	return numbers

if __name__ == '__main__':
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
		out.write('Case #%d:\n%s\n%s\n' % (case + 1, value[0], value[1]))
		out.flush()
	out.close()
