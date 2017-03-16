from math import *

T = input()

for case in range(1, T+1):
	ll = [int(x) for x in raw_input().strip().split()]
	[r, t] = ll
	M = int(0.25 * (-3 - 2 * r + sqrt(1 - 4 * r + 4 * r * r + 8 * t))) + 1
	P = (M)*(-1+2*M + 2*r)
	while P > t:
		M -= 1
		P = (M)*(-1+2*M + 2*r)

	print 'Case #%d:' % (case), M