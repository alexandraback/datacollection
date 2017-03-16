import sys
import collections
t = int(sys.stdin.readline())

prec = [set() for i in xrange(2000002)]

for i in xrange(1, 2000001):
	s = collections.deque(str(i))
	for u in xrange(len(s)):
		curNumber = int(''.join(s))
		s.rotate()
		if curNumber > i:
			prec[i].add(curNumber)

for testNumber in xrange(1, t+1):
	a,b = map(int, sys.stdin.readline().strip().split())
	ans = 0
	for i in xrange(a,b):
		for elem in prec[i]:
			if elem <= b:
				ans += 1
				
	print "Case #{0}: ".format(testNumber) + str(ans)
