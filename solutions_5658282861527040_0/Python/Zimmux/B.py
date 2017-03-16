import fileinput, sys
stdin = fileinput.input()

def ham(n):
	b = 0
	while n:
		b+=n&1
		n<<=1
	return b

def oneBits(n):
	b = []
	m = n
	p = 1
	while n:
		p*=2
		b+=[m/p]
		n<<=1
	return b

def solveCase():
	A, B, K = map(int,stdin.next().split())
	n = 0
	for a in xrange(A):
		for b in xrange(B):
			if a&b<K:
				n += 1
	return n

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())