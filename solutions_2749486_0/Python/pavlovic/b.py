#import math
import sys

t = int(sys.stdin.readline().strip())

for i in range(t):
	l = sys.stdin.readline().strip().split()
	x = int(l[0])
	y = int(l[1])

	x0 = 0
	y0 = 0

	s = ""
	while x0 != x:
		if x > x0:
			s += "WE"
			x0 += 1
		else:
			s += "EW"
			x0 -= 1

	while y0 != y:
		if y > y0:
			s += "SN"
			y0 += 1
		else:
			s += "NS"
			y0 -= 1

	print "Case #" + str(i + 1) + ": " + str(s)
