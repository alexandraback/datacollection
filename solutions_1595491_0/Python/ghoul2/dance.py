# /usr/bin/python
import sys


T = int(sys.stdin.readline())
for i in xrange(T):
	line = [ int(k) for k in sys.stdin.readline().split()]
	N = line[0]
	S = line[1]
	p = line[2]
	t = line[3:]
	y = 0
	for j in t:
		if j == 0 and p>0:
			continue
		if j >= p*3 - 2:
			y = y + 1
		elif j < (p*3 - 4):
			continue
		elif S>0:
			S = S - 1
			y = y + 1
	print "Case #%s: %s" % (i+1,y)



	
	
