#!/usr/bin/env python

FILE_NAME_BASE = 'C-large'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def calcPrimes(limit):
	'''Returns list of all primes under the given limit.
	'''
	sieve = [ True ] * limit
	sieve[0] = False
	sieve[1] = False
	i = 2
	while i * i < limit:
		if sieve[i]:
			for j in xrange(2 * i, limit, i):
				sieve[j] = False
		i += 1
	return [ i for i, prime in enumerate(sieve) if prime ]

# NOTE: This limit is not sufficient to find all possible jamcoins for the
#       large problem set, but it might find enough.
primes = calcPrimes(10 ** 8)
print 'Found %d primes' % len(primes)

def parse(inp):
	n, j = (int(x) for x in inp.readline().split())
	return n, j

def find_divider(n):
	for p in primes:
		if p * p > n:
			break
		if n % p == 0:
			return p
	return None

def solve(n, j):
	result = []
	for d in xrange(1 << (n - 2)):
		s = ('1{0:0%db}1' % (n - 2)).format(d)
		divs = []
		for b in xrange(2, 11):
			div = find_divider(int(s, b))
			if div is None:
				break
			divs.append(div)
		if len(divs) == 9:
			result.append((s, divs))
			print 'Found %d jamcoins' % len(result)
			if len(result) == j:
				break
	else:
		assert False, (n, j)

	return '\n' + '\n'.join(
		' '.join(str(e) for e in [s] + divs)
		for s, divs in result
		)

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
