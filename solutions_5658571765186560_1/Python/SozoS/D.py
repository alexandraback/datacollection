# Author: Davin Choo
# Email: cxjdavin@gmail.com

# Approach:
# X = 1 and X >= 7 are obvious
# Also, GABRIEL needs (R*C % X == 0) to even have any hope
# Drew out X-minoes for X = 2,3,4,5
# For each X-mino, found minimum sized grid needed to form rectangle

# Turns out, there seems to be some pattern to the dimensions
# X = n: Need at least _x_ (Piece(s) that caused that to happen)

# X = 2: Need at least 1x2 (The single piece is 1x2)
# X = 3: Need at least 2x3 (The L piece)
# X = 4: Need at least 3x4 (Any except square and L pieces)
# X = 5: Need at least 4x5 (The jagged staircase piece)
# X = 6: Need at least 5x6 (GUESSED from pattern above...)

# Some additional observations
# X = 1: GABRIEL always wins
# X = 2: GABRIEL wins iff R*C = even number
# X = 3: GABRIEL loses/RICHARD wins iff it is a 1 row/column board (RICHARD pics the non-straight omino)
# X >= 7: RICHARD always wins by picking a omino with a hole inside

T = int(raw_input())

for i in xrange(0, T):
	temp = raw_input().split()
	X = int(temp[0])
	R = int(temp[1])
	C = int(temp[2])

	output = ""
	trivial_fail = False
	if R*C % X != 0: # Trivial check...
		output = "RICHARD"
		trivial_fail = True
	
	if not trivial_fail:
		if X == 1:
			output = "GABRIEL"
		elif X == 2:
			# Need at least 1x2
			if (R >= 1 and C >= 2) or (R >= 2 and C >= 1):
				output = "GABRIEL"
			else:
				output = "RICHARD"
		elif X == 3:
			# Need at least 2x3
			if (R >= 2 and C >= 3) or (R >= 3 and C >= 2):
				output = "GABRIEL"
			else:
				output = "RICHARD"
		elif X == 4:
			# Need at least 3x4
			if (R >= 3 and C >= 4) or (R >= 4 and C >= 3):
				output = "GABRIEL"
			else:
				output = "RICHARD"
		elif X == 5:
			# Need at least 4x5
			if (R >= 4 and C >= 5) or (R >= 5 and C >= 4):
				output = "GABRIEL"
			else:
				output = "RICHARD"
		elif X == 6:
			# Guess from pattern of 2~5
			# Need at least 5x6
			if (R >= 5 and C >= 6) or (R >= 6 and C >= 5):
				output = "GABRIEL"
			else:
				output = "RICHARD"
		else: # X >= 7
			output = "RICHARD"

	print "Case #" + str(i+1) + ": " + str(output)