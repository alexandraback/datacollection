T = int(raw_input())

def doprob():
	read = raw_input()
	read = [int(x) for x in read.split()]
	X = read[0]
	R = read[1]
	C = read[2]
	R, C = tuple(sorted([R, C]))
	if X >= 7:
		return "RICHARD"
	if (R*C) % X != 0:
		return "RICHARD"
	if X in [1, 2]:
		return "GABRIEL"
	if X == 3:
		if R == 1:
			return "RICHARD"
		else:
			return "GABRIEL"
	if X == 4:
		if R in [1, 2]:
			return "RICHARD"
		else:
			return "GABRIEL"
	if X == 5:
		if R in [1, 2, 3]:
			return "RICHARD"
		else:
			return "GABRIEL"
	if X == 6:
		if R in [1, 2, 3, 4]:
			return "RICHARD"
		else:
			return "GABRIEL"



for qq in xrange(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())