import sys

T = int(sys.stdin.readline())

for i in xrange(T):
	c = i + 1
	s = 0
	A,B = [ int(i) for i in sys.stdin.readline().split()]
	for n in xrange(A,B):
		pairs = []
		sn = list(str(n))
		for j in xrange(1,len(sn)):
			sn = [ sn.pop()] + sn
			m = int("".join(sn)) 
			if m > n and m <= B and m not in pairs:
				s = s+1
				pairs.append(m)
	print "Case #%s: %s" % (c,s)
