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

def flip(s):
	return ''.join('-' if c is '+' else '+' for c in s[::-1])

def flipTo(s, n):
	return flip(s[:n+1]) + s[n+1:]

oo = 10000000000
seen = set()

def simplify(s):
	result = []
	last = None
	for c in s:
		if c != last:
			result.append(c)
			last = c
	return ''.join(result)

@memo
def solve(s):
	if '++' in s or '--' in s: return solve(simplify(s))
	if s in seen: return oo
	seen.add(s)
	if '-' not in s: return 0
	return 1 + min(map(solve, (flipTo(s, n) for n in range(len(s)))))

T, = get()
for caseNumber in range(1, T+1):
	s, = getl()
	put(caseNumber, solve(s))

