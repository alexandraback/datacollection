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

def replace(s, i = 0):
	if i == len(s):
		yield s
	else:
		if s[i] != '?':
			for ans in replace(s, i+1):
				yield ans
		else:
			for digit in '0123456789':
				for ans in replace(s[:i] + digit + s[i+1:], i+1):
					yield ans

def solve(s1, s2):
	s1p = list(replace(s1))
	s2p = list(replace(s2))

	a, b = min(((a, b) for a in s1p for b in s2p), key=lambda (a,b): (abs(int(a) - int(b)), int(a), int(b)))
	return '%s %s' % (a, b)

T, = get()
for caseNumber in range(1, T+1):
	put(caseNumber, solve(*getl()))

