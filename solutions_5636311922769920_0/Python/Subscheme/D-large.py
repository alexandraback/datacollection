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

def solve(K, C, S):
	if S * C < K:
		return 'IMPOSSIBLE'

	toEliminate = range(K)
	positions = []
	while toEliminate:
		p = 0
		for i in range(C):
			if not toEliminate:
				break
			p += toEliminate.pop() * K**i
		positions.append(p)

	assert len(positions) <= S
	return ' '.join(str(p+1) for p in positions)

T, = get()
for caseNumber in range(1, T+1):
	put(caseNumber, solve(*get()))

