#!/usr/bin/python
T = raw_input()
T = int(T)
def letters(N):
	s = set()
	while (N):
		s.add(N%10)
		N = N/10
	return s

for i in range(T):
	N = int(raw_input())
	if N == 0:
		print 'Case #%d: INSOMNIA' %(i+1)
		continue
	AL = set()
	for k in range(1000):
		n = N*(k+1)
		AL = AL.union(letters(n))
	#	print len(AL), AL
		if len(AL) == 10:
			print "Case #%d: %d" %(i+1, n)
			break
		
	

