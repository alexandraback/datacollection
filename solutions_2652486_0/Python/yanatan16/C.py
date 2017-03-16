'''
CodeJam 2013 Round 1A
Problem C: Good Luck
Author: Jon Eisen

This solution uses [pycodejam](http://github.com/yanatan16/pycodejam).
'''
from codejam import CodeJam, parsers
from itertools import *

def merge(a, b, f=max):
	c = []
	for x in set(list(a)+list(b)):
		c += [x] * f(a.count(x), b.count(x))
	return c

def mergemult(known, possibles):
	poss = reduce(lambda a,b: merge(a,b,f=min), possibles[1:], possibles[0])
	return merge(known, poss)

def solve(n, m, k, nums):
	implications = {}
	possible = range(2, m+1)
	sets = chain.from_iterable((combinations_with_replacement(possible, i) for i in xrange(n+1)))
	mult = lambda a: reduce(lambda x,y: x*y, a, 1)
	for s in sets:
		try:
			implications[mult(s)] += [s]
		except KeyError:
			implications[mult(s)] = [s]

	output = "\n"
	for numset in nums:
		output += ''.join(map(str,subsolve(implications, k, n, numset))) + '\n'
	return output[:-1]

def subsolve(implications, k, N, numset):
	implies = []

	for n in numset:
		implies += [implications[n]]

	level = {}

	for implied in implies:
		try:
			level[len(implied)] += [implied]
		except KeyError:
			level[len(implied)] = [implied]

	full = []
	for l, impl in sorted(level.items()):
		if l == 1:
			for ii in impl:
				full = merge(full, ii[0])
		else:
			for ii in impl:
				full = mergemult(full, ii)

	assert len(full) <= N, 'too big %s' % full

	return full + (N - len(full)) * [2]

@parsers.iter_parser
def parse(nxt):
	inxt = lambda: [int(x) for x in nxt().split()]
	r, n, m, k = inxt()
	nums = []
	for _ in xrange(r):
		nums += [inxt()]

	return n, m, k, nums

if __name__ == "__main__":
	CodeJam(parse, solve).main()