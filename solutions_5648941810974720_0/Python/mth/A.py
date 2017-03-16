#!/usr/bin/env python

FILE_NAME_BASE = 'A-small-attempt0'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

from collections import defaultdict

def parse(inp):
	s = inp.readline().strip()
	return s,

# "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"

def solve(s):
	freqs = defaultdict(int)
	for c in s:
		freqs[c] += 1
	#print freqs

	digits = []

	def eatWord(word, digit, uniqueLetter):
		while freqs[uniqueLetter] > 0:
			for c in word:
				freqs[c] -= 1
				assert freqs[c] >= 0, word
			digits.append(digit)

	eatWord('ZERO', 0, 'Z')
	eatWord('SIX', 6, 'X')
	eatWord('TWO', 2, 'W')
	eatWord('EIGHT', 8, 'G')
	eatWord('SEVEN', 7, 'S')
	eatWord('THREE', 3, 'H')
	eatWord('FOUR', 4, 'R')
	eatWord('FIVE', 5, 'F')
	eatWord('ONE', 1, 'O')
	eatWord('NINE', 9, 'I')

	assert all(f == 0 for f in freqs.itervalues()), freqs

	return ''.join(str(d) for d in sorted(digits))

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
