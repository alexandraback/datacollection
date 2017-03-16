'''
CodeJam 2013 Round 1A
Problem C: Good Luck
Author: Jon Eisen

This solution uses [pycodejam](http://github.com/yanatan16/pycodejam).
'''
from codejam import CodeJam, parsers
from itertools import *

c = count()

def merge(a, b, f=max):
	c = []
	for x in set(list(a)+list(b)):
		c += [x] * f(a.count(x), b.count(x))
	return c

def mergemult(known, possibles):
	poss = reduce(lambda a,b: merge(a,b,f=min), possibles[1:], possibles[0])
	return merge(known, poss)

def remove(a, b):
	a = [x for x in a]
	for x in b:
		try:
			a.remove(x)
		except:
			pass
	return a

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
		output += ''.join(map(str,subsolve(implications, k, n, m, numset))) + '\n'
	return output[:-1]

def mean(a):
	return sum(a) / len(a)

def subsolve(implications, k, N, m, numset):
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

	if len(full) == N:
		return full

	# Now educated guessing
	now = N - len(full)
	try:
		del level[1]
	except:
		pass

	possibilities = chain.from_iterable(level.values())
	newposs = ([remove(p, full) for p in pp] for pp in possibilities)
	newposs = ([p for p in pp if len(p) > 0 and len(p) <= now]  for pp in newposs)
	newposs = [pp for pp in newposs if len(pp) > 0]

	def satisfy(perm):
		sp = perm
		for poss in newposs:
			f = False
			for p in poss:
				if len(remove(p, sp)) == 0:
					f = True
					break
			if not f:
				return False
		return True

	def value(poss):
		return len(poss) * (now - mean(map(len, poss)))

	p0 = min([(value(poss), poss) for poss in newposs])[1]
	smartperm = ((p0p + list(c) for c in combinations_with_replacement(range(2,m+1),now-len(p0p))) for p0p in p0)
	perms = list(chain.from_iterable(smartperm))
	sperms = (p for p in perms if satisfy(p))

	return full + list(next(sperms, [2] * now))

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