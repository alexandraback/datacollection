#from __future__ import division
import string
import sys

def GCD(a,b):
	ma = max(a,b)
	mi = min(a,b)
	if ma % mi != 0:
		return GCD(mi,ma%mi)
	return mi

def check(Q):
	count = 0
	temp = Q 
	while(Q & 1 != 1):
		Q = Q >> 1
		count += 1
	
	if temp & ~(1 << count) == 0:
		return True
	else:
		return False

def cal(P,Q):
	gcd = GCD(P,Q)
	P = P/gcd
	Q = Q/gcd

	if not check(Q):
		return -1
	
	count = 0
	while(Q != 0 and P < Q):
		Q = Q >> 1
		count += 1
		
	return count
	if Q & ~(1 << (count - 1)) == 0:
		return count
	else:
		return 'impossible'

if __name__ == '__main__':
	if len(sys.argv) != 2:
		sys.exit(0)

	f = open(sys.argv[1])
	f.readline()
	
	count = 1
	for line in f:
		P,Q = line.rstrip().split('/')
		P = string.atoi(P)
		Q = string.atoi(Q)
		
		result = cal(P,Q)
		if result == -1:
			print 'Case #%r: impossible' % count
		else:
			print 'Case #%r: %r' % (count,result)
		count += 1
		
