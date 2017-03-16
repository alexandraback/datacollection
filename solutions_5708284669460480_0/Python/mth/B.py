#!/usr/bin/env python

FILE_NAME_BASE = 'B-small-attempt0'
NUM_PROCESSES = 4
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

from itertools import product

def parse(inp):
	numKeys, targetLen, typeLen = (int(x) for x in inp.readline().split())
	keys = inp.readline().strip()
	assert len(keys) == numKeys
	target = inp.readline().strip()
	assert len(target) == targetLen
	return keys, target, typeLen

def maxPrefix(s):
	return reduce(max, (i for i in xrange(1, len(s)) if s[:i] == s[-i:]), 0)

def solve(keys, target, typeLen):
	if set(target) - set(keys):
		return 0.0

	assert len(target) <= typeLen
	maxBananas = 1 + (typeLen - len(target)) / (len(target) - maxPrefix(target))

	matches = 0
	words = 0
	for typed in product(keys, repeat=typeLen):
		word = ''.join(typed)
		words += 1
		i = 0
		while True:
			i = word.find(target, i)
			if i == -1:
				break
			matches += 1
			i += 1

	return maxBananas - float(matches) / float(words)

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
