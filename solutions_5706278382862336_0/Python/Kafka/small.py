#python
from sys import stdin
from fractions import gcd
import math
f = open('small.out','w')

T = int(stdin.next())

def is2power(a):
	if a < 2: return 0
	if (a & a - 1) == 0:
		return 1
	else:
		return 0

def log2(x):
	x = float(x)
	temp = math.log(x)/math.log(2)
	return int(temp)

for case in xrange(1,T+1):
	print 'Case #%d: ' %case,
	print >> f, 'Case #%d: ' %case,
	p, q = map(int,stdin.next().split('/'))
	com = gcd(p,q)
	p, q = p/com, q/com
	if not is2power(q):
		print 'Impossible'
		print>>f, 'Impossible'
		continue
	else:

		print log2(q) - log2(p)
		print>>f, log2(q) - log2(p)
		

	
	

f.close()
