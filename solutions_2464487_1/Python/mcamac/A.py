from math import *

T = input()

for case in range(1, T+1):
	ll = [long(x) for x in raw_input().strip().split()]
	[r, t] = ll
	M = long(0.25 * (-3 - 2 * r + sqrt(1 - 4 * r + 4 * r * r + 8 * t))) + 4
	P = (M)*(-1+2*M + 2*r)
	while P > t and M >= 1:
		M -= 1
		P = (M)*(-1+2*M + 2*r)
	if M < 0:
		M = 1
	print 'Case #%d:' % (case), M