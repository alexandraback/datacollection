#!/usr/bin/env python

#FILE_NAME_BASE = 'C-example'
FILE_NAME_BASE = 'C-small-1-attempt0'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

from collections import defaultdict

def parse(inp):
	numSets, setSize, maxVal, numSamples = \
		(int(x) for x in inp.readline().split())
	samples = tuple(
		tuple(int(x) for x in inp.readline().split())
		for _ in xrange(numSets)
		)
	return setSize, maxVal, samples

def solve(setSize, maxVal, samples):

	def iterSets(i):
		if i == 0:
			yield ()
		else:
			for v in xrange(2, maxVal + 1):
				for s in iterSets(i - 1):
					yield s + (v, )

	def iterProducts(s):
		if s:
			n = s[0]
			for prod in iterProducts(s[1 :]):
				yield prod
				yield n * prod
		else:
			yield 1

	products = defaultdict(lambda: defaultdict(int))
	for s in iterSets(setSize):
		s = tuple(sorted(s))
		for p in iterProducts(s):
			products[p][s] += 1

	#print setSize, maxVal, samples
	#print products
	#print

	guesses = []
	for sample in samples:
		possible = None
		for prod in sample:
			if possible is None:
				possible = dict(products[prod].iteritems())
			else:
				newPossible = {}
				for s, freq in products[prod].iteritems():
					oldFreq = possible.get(s, 0)
					if oldFreq != 0:
						newPossible[s] = oldFreq * freq
				possible = newPossible

		#print sample, possible
		bestFreq = -1
		bestSet = None
		for s, freq in possible.iteritems():
			if freq > bestFreq:
				bestFreq = freq
				bestSet = s

		guesses.append(''.join(str(d) for d in bestSet))

	return ''.join('\n' + guess for guess in guesses)

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
		out.write('Case #%d:%s\n' % (case + 1, value))
		out.flush()
	out.close()

if __name__ == '__main__':
	main()
