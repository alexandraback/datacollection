from sys import setrecursionlimit as slr
slr(10**9)

def memo(f):
	cache = dict()
	def wrap(*args):
		if args not in cache: cache[args] = f(*args)
		return cache[args]
	return wrap

getl = lambda: raw_input().strip().split()
get = lambda: map(int, getl())

def put(caseNumber, result):
	print "Case #%d: %s" % (caseNumber, result)

def possible(real, fake):
	firstWords = set(first for first, second in real)
	secondWords = set(second for first, second in real)

	return all(first in firstWords and second in secondWords for first, second in fake)

def solve(l):
	best = 0
	for i in range(2**len(l)):
		real = [x for j,x in enumerate(l) if i & (1 << j)]
		fake = [x for j,x in enumerate(l) if not (i & (1 << j))]
		if possible(real, fake):
			best = max(best, len(fake))
	return best

T, = get()
for caseNumber in range(1, T+1):
	put(caseNumber, solve([getl() for i in range(get()[0])]))

