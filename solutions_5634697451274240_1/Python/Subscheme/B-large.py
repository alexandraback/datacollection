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

def solve(s):
	if len(s) == 0:
		return 0
	amount = 0
	last = s[0]
	for c in s + '+':
		if c != last:
			amount += 1
			last = c
	return amount 

T, = get()
for caseNumber in range(1, T+1):
	s, = getl()
	put(caseNumber, solve(s))

