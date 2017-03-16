
import math

def gcd(a, b):
	while a != b:
		if a > b:
			a = a - b
		else:
			b = b - a
	return a

z = 2**40
for testcase in xrange(input()):
	n, d = [int(_) for _ in raw_input().split('/')]
	g = gcd(n, d)
	n /= g
	d /= g
	if z % d != 0:
		ans = 'impossible'
	else:
		f = z / d
		ans = 40 - int(math.floor(math.log(f*n, 2)))
	print 'Case #{0}: {1}'.format(testcase + 1, ans)
