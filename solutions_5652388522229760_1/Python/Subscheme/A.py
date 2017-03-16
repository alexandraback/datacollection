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

def solve(N):
	if N == 0:
		return 'INSOMNIA'
	digits = set(str(N))
	current = N
	while len(digits) < 10:
		current += N
		digits |= set(str(current))
	return current

T, = get()
for caseNumber in range(1, T+1):
	put(caseNumber, solve(*get()))
