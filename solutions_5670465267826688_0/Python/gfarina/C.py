import sys

lines = sys.stdin.readlines()

T = int(lines[0])

def neg(s):
	if s[0] == '-':
		return s[1]
	else:
		return '-' + s[0]

def isneg(s):
	return int(s[0] == '-')

def qprod(a, b):
	negs = isneg(a) + isneg(b)
	if negs == 1:
		return neg(qprod(neg(a), b))
	if negs == 2:
		return qprod(neg(a), neg(b))

	if a == '1':
		return b
	if b == '1':
		return a
	elif a == b:
		return '-1'
	elif a == 'i' and b == 'j':
		return 'k'
	elif a == 'i' and b == 'k':
		return '-j'
	elif a == 'j' and b == 'k':
		return 'i'
	else:
		return neg(qprod(b, a))

def qprods(s):
	ans = '1'
	for x in list(s):
		ans = qprod(ans, x)
	return ans

def lm(s, target):
	pr = '1'
	for pos, x in enumerate(list(s)):
		pr = qprod(pr, x)
		if pr == target:
			return pos + 1

	return len(s)

def lmR(s, target):
	pr = '1'
	for pos, x in enumerate(list(s[::-1])):
		pr = qprod(x, pr)
		if pr == target:
			return pos + 1

	return len(s)

def qpow(a, n):
	ans = '1'
	for _ in xrange(n):
		ans = qprod(ans, a)
	return ans

if False:
	syms = ['1', 'i', 'j', 'k']

	for a in syms:
		for b in syms:
			print qprod(a, b),
		print

for t in xrange(1, T + 1):
	L, orig_X = map(int, lines[2 * t - 1].split())
	X = orig_X #min(orig_X, 12)
	orig_s = lines[2 * t].strip()
	s = orig_s * X

	if qpow(qprods(orig_s), orig_X % 4) != '-1':
		ans = 'NO'
	else:
		if lm(s, 'i') + lmR(s, 'k') < len(s):
			ans = 'YES'
		else:
			ans = 'NO'

	if False and t == 12:
		print L, X
		print orig_s.strip()
		print qpow(qprods(orig_s), X % 4)
		print lm(s, 'i'), qprods(s[:lm(s, 'i')])
		print lmR(s, 'k'), qprods(s[-lmR(s, 'k'):])

	print "Case #%d: %s" % (t, ans)