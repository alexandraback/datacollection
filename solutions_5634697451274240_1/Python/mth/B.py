#!/usr/bin/env python

FILE_NAME_BASE = 'B-large'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	s = inp.readline().strip()
	return s,

def flip(s):
	return ''.join(
		{'+': '-', '-': '+'}[c]
		for c in reversed(s)
		)

'''
Splitting up a sequence isn't going to 


'''

def solve_count(s):
	prev = '?'
	count = 0
	for c in s.rstrip('+'):
		if c != prev:
			count += 1
			prev = c
	return count

def solve_strategy(s):
	flips = 0
	while True:
		#print s, flips
		if s[0] == '+':
			i = s.find('-')
			if i == -1:
				break
		else:
			i = s.rfind('-') + 1
			if i == 0:
				break
		s = flip(s[:i]) + s[i:]
		flips += 1
	return flips

def solve_slow(init):
	n = len(init)
	old = set()
	curr = set([init])
	flips = 0
	while True:
		if '+' * n in curr:
			return flips
		old |= curr
		new = set()
		for s in curr:
			for i in xrange(1, n + 1):
				sf = flip(s[:i]) + s[i:]
				if sf not in old:
					new.add(sf)
		curr = new
		flips += 1

def solve(s):
	count = solve_count(s)
	strat = solve_strategy(s)
	assert count == strat, s
	if len(s) <= 10:
		slow = solve_slow(s)
		assert strat == slow, s
	return count

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
