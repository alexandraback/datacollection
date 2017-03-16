import sys
rl=sys.stdin.readline

def ispal(v):
	v = str(v)
	return v == v[::-1]

def go(A, B):
	c = 0
	for i in xrange(A,B+1):
		sq = int(i**0.5 + 1e-9)
		if sq ** 2 == i and ispal(i) and ispal(sq):
			c += 1
	return c

T=int(rl())
for i in xrange(1,T+1):
	A, B = map(int, rl().split())
	print "Case #%d: %d" % (i, go(A, B))
