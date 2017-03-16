#!/usr/bin/python2.7

for case in range(input()):
	R, C, W = map(int, raw_input().split())

	sol = 0
	if (W == 1):
		sol = R * C
	else:
		sol = (R-1) * (C // W)
		if (W == C) or (W == (C-1)):
			sol += C
		else:
			if (W > (C//2)):
				sol += W + 1
			else:
				sol += (C // W) + W
				if ((C % W) == 0):
					sol -= 1
#				if ((C % 2) == 0) and ((C % W) == 0):
#					sol -= 1
#
	print 'Case #%s: %s' % ((case + 1), sol)

