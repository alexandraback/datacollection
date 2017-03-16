#!/usr/bin/env python

FILE_NAME_BASE = 'C-small-attempt0'
NUM_PROCESSES = 4
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	maxSame, numOld, maxValue = (int(x) for x in inp.readline().split())
	oldCoins = tuple(int(x) for x in inp.readline().split())
	assert len(oldCoins) == numOld
	return oldCoins, maxSame, maxValue

def reach(coins):
	values = set()
	def rec(s, i, coins=coins, n=len(coins)):
		if i == n:
			values.add(s)
		else:
			rec(s, i + 1)
			rec(s + coins[i], i + 1)
	rec(0, 0)
	values.remove(0)
	return values

def solve(oldCoins, maxSame, maxValue):
	values = set(xrange(1, maxValue + 1))
	def rec(coins):
		missing = values - reach(tuple(coins))
		if not missing:
			return 0
		v = min(missing)
		m = maxValue
		for c in xrange(1, v + 1):
			if c not in coins:
				coins.add(c)
				m = min(m, 1 + rec(coins))
				coins.remove(c)
		return m
	return rec(set(oldCoins))

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
