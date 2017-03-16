# A

import sys


T = int(sys.stdin.readline())

for t in xrange(1, T+1):
	J = map(int,sys.stdin.readline().split())
	del J[0]

	
	X = sum(J)
	ok = [False] * len(J)
	Xt = X
	Nt = len(J)
	Y = [0.0] * Nt
	for i in range(Nt):
		if J[i] * len(J) >= 2*X:
			ok[i] = True
			Xt -= J[i]
			Nt -= 1
	
	for i in range(len(J)):
		if ok[i]: continue
		Y[i] = (float(Xt + X)/Nt - J[i]) / X * 100

	print 'Case #%d: %s' % (t, ' '.join(map(str, Y)))
	
