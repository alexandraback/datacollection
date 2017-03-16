import sys
import math

def findRing(r, t):
	result = long(0)
	radius = long(r+1)
	while t > 0 and t >= ((radius**2) - ((radius-1)**2)):
		t -= ((radius**2) - ((radius-1)**2))
		result += long(1)
		radius += long(2)
	return result

T = int(sys.stdin.readline())
i = 0
while(i < T):
	num = sys.stdin.readline().split()
	r = long(num[0])
	t = long(num[1])
	print "Case #" + str(i+1) + ": " + str(findRing(r, t))
	i += 1