#!/usr/bin/env python

FILE_NAME_BASE = 'C-small-attempt0'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	length, repeat = (int(x) for x in inp.readline().split())
	letters = inp.readline().strip()
	assert len(letters) == length
	return letters, repeat

def solve(letters, repeat):
	numbers = tuple(ord(letter) - ord('h') for letter in letters)

	# Set up an 8x8 multiply table.
	# Indices 0-7 are: 1, i, j, k, -1, -i, -j, -k.
	mult = []
	for row in (
			('1',  'i',  'j',  'k'),
			('i', '-1',  'k', '-j'),
			('j', '-k', '-1',  'i'),
			('k',  'j', '-i', '-1'),
			):
		multRow = []
		for cell in row:
			ch = cell[-1]
			d = 0 if ch == '1' else (ord(ch) - ord('h'))
			if cell[0] == '-':
				d += 4
			multRow.append(d)
		mult.append(multRow)
	for multRow in mult:
		multRow.extend([d ^ 4 for d in multRow])
	for multRow in list(mult):
		mult.append([d ^ 4 for d in multRow])

	# For the small input set, this is feasible.
	numbers = numbers * repeat

	# Instead of splitting, we check for cumulative results:
	# i, k (i*j) and -1 (i*j*k).
	seenI = False
	seenK = False
	v = 0
	for n in numbers:
		seenI |= v == 1
		seenK |= seenI and v == 3
		v = mult[v][n]
	return 'YES' if seenI and seenK and v == 4 else 'NO'

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
