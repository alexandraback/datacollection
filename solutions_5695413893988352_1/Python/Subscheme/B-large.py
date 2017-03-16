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

	@memo
	def solMin(i):
		rem = len(s1) - 1 - i
		if rem < 0:
			return 0, '', ''

		c1 = s1[i]
		c2 = s2[i]

		if c1 == '?' and c2 == '?':
			d1 = 0
			d2 = 9
		elif c1 == '?':
			d1 = 0
			d2 = int(c2)
		elif c2 == '?':
			d1 = int(c1)
			d2 = 9
		else:
			d1 = int(c1)
			d2 = int(c2)

		digitDiff = d1 - d2
		r, r1, r2 = solMin(i+1)
		return r + digitDiff * (10 ** rem), str(d1) + r1, str(d2) + r2

	@memo
	def solMax(i):
		rem = len(s1) - 1 - i
		if rem < 0:
			return 0, '', ''

		c1 = s1[i]
		c2 = s2[i]

		if c1 == '?' and c2 == '?':
			d1 = 9
			d2 = 0
		elif c1 == '?':
			d1 = 9
			d2 = int(c2)
		elif c2 == '?':
			d1 = int(c1)
			d2 = 0
		else:
			d1 = int(c1)
			d2 = int(c2)

		digitDiff = d1 - d2
		r, r1, r2 = solMax(i+1)
		return r + digitDiff * (10 ** rem), str(d1) + r1, str(d2) + r2

	def evaluateOptionKey((delta, a, b)):
		return abs(delta), int(a), int(b)

	@memo
	def solEq(i):
		rem = len(s1) - 1 - i
		p = 10 ** rem
		if rem < 0:
			return 0, '', ''
		
		c1 = s1[i]
		c2 = s2[i]

		if c1 == '?' or c2 == '?':
			options = []

			# Make first digit smaller
			if c1 == '?':
				if c2 == '?':
					options.append(('0', '1', solMax(i+1)))
				elif c2 != '0':
					options.append((str(int(c2) - 1), c2, solMax(i+1)))
			else:
				assert c2 == '?' and c1 != '?'
				if c1 != '9':
					options.append((c1, str(int(c1) + 1), solMax(i+1)))

			# Make first digit larger
			if c1 == '?':
				if c2 == '?':
					options.append(('1', '0', solMin(i+1)))
				elif c2 != '9':
					options.append((str(int(c2)+1), c2, solMin(i+1)))
			else:
				assert c2 == '?' and c1 != '?'
				if c1 != '0':
					options.append((c1, str(int(c1) - 1), solMin(i+1)))

			# Make both digits equal
			equalDigit = '0' if c1 == '?' and c2 == '?' else (c1 if c2 == '?' else c2)
			options.append((equalDigit, equalDigit, solEq(i+1)))

			assert all(0 <= int(d1) <= 9 and 0 <= int(d2) <= 9 for d1, d2, _ in options)

			options = [(r + p * (int(d1) - int(d2)), d1 + r1, d2 + r2) for d1, d2, (r, r1, r2) in options]
			return min(options, key=evaluateOptionKey)

		else:
			digitDiff = int(c1) - int(c2)
			if digitDiff > 0:
				r, r1, r2 = solMin(i+1)
				return p * digitDiff + r, c1 + r1, c2 + r2
			elif digitDiff < 0:
				r, r1, r2 = solMax(i+1)
				return p * digitDiff + r, c1 + r1, c2 + r2
			else:
				r, r1, r2 = solEq(i+1)
				return r, c1 + r1, c2 + r2


	return '%s %s' % solEq(0)[1:]

T, = get()
for caseNumber in range(1, T+1):
	put(caseNumber, solve(*getl()))

