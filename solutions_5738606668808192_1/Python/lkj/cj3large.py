from math import sqrt

#some false positives
def isprime(n):
	if n < 2:
		return False
	if n < 4:
		return True

	alist = [2, 325, 9375, 28178, 450775, 9780504, 1795265022]

	s = 0
	while ((n-1) >> s) % 2 == 0:
		s += 1
	d = (n-1) >> s #-> d * (2**s) = d * (1<<s) = n - 1

	for a in alist:
		if a > n - 2:
			continue
		x = pow(a, d, n)
		if x == 1 or x == n-1:
			continue
		for i in range(0, s):
			x = x**2 % n
			if x == 1:
				return False
			if x == n-1:
				break
		else:
			return False
	return True

def basebto10(s, b):
	l = len(s)
	n = 0
	bi = 1
	for i in range(l):
		n += int(s[l-i-1])*bi
		bi *= b
	return n

def getdiv(n):
	for i in range(2, 1000):
		if n%i == 0:
			return i
	return n

def isjc(n, c):
	assert(n >= 2)
	if len(c) != n:
		print('want len', n, 'checking c = "%s"' % c)
	assert(len(c) == n)
	assert(c[0] == c[-1] == '1')
	divs = []
	for b in range(2, 11):
		cb = basebto10(c, b)
		if isprime(cb):
			return (False, [])
		d = getdiv(cb)
		if d == cb:
			return (False, [])
		divs.append(d)
	return True, divs

def solve(n, j):
	for i in range(2**(n-2)):
		if j <= 0:
			break
		c = ('1{:0%ib}1'%(n-2)).format(i)
		o = isjc(n, c)
		if o[0]:
			print(c, end=' ')
			for i in o[1]:
				print(i, end=' ')
			print()
			j -= 1
	assert(j == 0)


tc = int(input())
for t in range(1,tc+1):
	n, j = [int(x) for x in input().split()]
	print('Case #%i:' % t)
	solve(n,j)
