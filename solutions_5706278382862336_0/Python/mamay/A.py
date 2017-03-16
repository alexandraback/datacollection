def gcd(x, y):
	if x == 0:
		return y
	else:
		return gcd(y%x, x)

def pow2(x):
	while x %2 == 0:
		x /= 2
	return (x == 1)

def elf(a, b):
	x = bin(a)
	y = bin(b)
	return len(y) - len(x)


for i in xrange(input()):
	a, b = [int(l) for l in raw_input().split('/')]
	d = gcd(a, b)
	a /= d
	b /= d
	if pow2(b):
		print 'Case #%d: %d' %(i+1, elf(a, b))
	else:
		print 'Case #%d: impossible' %(i+1)
