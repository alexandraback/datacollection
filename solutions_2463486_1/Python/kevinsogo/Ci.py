def rev(v, base=10, a=0):
	return a if v == 0 else rev(v / base, base, a * base + v % base)

def f(b, t, d, pb):
	''' nonzero d-digit numbers base b whose sum of squares of digits < t, increasing. pb must be b^d '''
	from itertools import count
	if d == 1:
		for e in count(1):
			see = e * e
			if see < t:
				yield e, see, e
			else:
				break
	else:
		pb /= b
		for w,s,rw in f(b, t, d - 1, pb):
			wb = w * b
			for e in count():
				see = s + e * e
				if see < t:
					yield wb + e, see, e*pb + rw
				else:
					break


def palindromes(b=10):
	from itertools import count

	# one-digit palindromes
	for e in count():
		see = e * e
		if see < b:
			yield e
		else:
			break

	lim = 1
	for d in count(1):
		lim *= b

		# 2d-digit palindromes
		for w,s,rw in f(b,(b-1)/2+1,d,lim):
			yield w*lim + rw

		# 2d+1-digit palindromes
		for w,s,rw in f(b,(b-1)/2+1,d,lim):
			s *= 2
			for e in count():
				see = s + e * e
				if see < b:
					yield (w*b + e)*lim + rw
				else:
					break

goods = []
for v in palindromes():
	if v > 10**50:
		break
	goods.append(v*v)

lgoods = len(goods)

def ct(n):
	a, b = 0, lgoods
	while b > a + 1:
		c = a + b >> 1
		if goods[c] <= n:
			a = c
		else:
			b = c
	return b

z = int(raw_input())
for cas in xrange(1,z+1):
	A, B = map(int, raw_input().strip().split())
	ans = ct(B) - (ct(A - 1) if A > 0 else 0)
	print "Case #%d: %d" % (cas, ans)
