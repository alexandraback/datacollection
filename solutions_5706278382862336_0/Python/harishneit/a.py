from fractions import gcd
from math import log

t = int(raw_input())

def number_util_first_one(n, d, count):
	if(gcd(n, d) > 1):
		return number_util_first_one(n/gcd(n, d), d/gcd(n, d), count)
	if n == 0:
		return count
	elif n < d:
		return number_util_first_one(2*n, d, count + 1)
	else:
		if(number_util_first_one(n - d, d, 0) <= 40 - count):
			return count
		else:
			-1

for i in xrange(1, t + 1):
	n, d = [int(token) for token in raw_input().split('/')]
	g = gcd(n, d)
	n, d = n/g, d/g
	if d != 2 ** int(log(d, 2)):
		print 'Case #%d: impossible' % i
	else:
		n_u_f1 = number_util_first_one(n, d, 0)
		if n_u_f1 <= 40 and n_u_f1 >= 0:
			print 'Case #%d: %d' % 	(i, n_u_f1)
		else:
			print 'Case #%d: impossible' % i
