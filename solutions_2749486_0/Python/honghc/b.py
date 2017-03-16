T = int(raw_input())

Y_plus_one = 'SN'
Y_minus_one = 'NS'
X_plus_one = 'WE'
X_minus_one = 'EW'

for case in range(1, T+1):
	X, Y = [int(x) for x in raw_input().split(' ')]
	out = ''
	x_moved = False
	if X % 2 != 0:
		if X > 0:
			X -= 1
			out += 'E'
		elif X < 0:
			X += 1
			out += 'W'
		x_moved = True
	if Y % 2 != 0:
		if not x_moved:
			if Y > 0:
				Y -= 1
				out += 'N'
			elif Y < 0:
				out += 'S'
				Y += 1
		else:
			if Y > 0:
				Y -= 1
				out += 'SN'
			elif Y > 0:
				Y += 1
				out += 'NS'
	while X != 0 or Y != 0:
		if X > 0:
			out += X_plus_one
			X -= 1
		elif X < 0:
			out += X_minus_one
			X += 1
		elif Y > 0:
			out += Y_plus_one
			Y -= 1
		elif Y < 0:
			out += Y_minus_one
			Y += 1
	print "Case #{0}: {1}".format(case, out)