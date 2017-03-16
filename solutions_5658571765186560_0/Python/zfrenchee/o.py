

def main():

	NumberOfTestCases = int(raw_input())

	for T in range(1, NumberOfTestCases+1):

		X, R, C = map(int, raw_input().split())

		print 'Case #'+`T`+': '+Winner(X, R, C)


def Winner(X, R, C):

	# Deal with the base cases

	if (R*C) % X != 0: return 'RICHARD'

	if (X == 1 or X == 2) and R*C > 0: return 'GABRIEL'

	if (X == 3 and ((R == 3 and C == 2) or (R == 2 and C == 3))): return 'GABRIEL'

	if X >= 7: return 'RICHARD'

	if max(R,C) < X: return 'RICHARD'


	# Now we're in the space of X = 4, 5, or 6
	# and the area of the grid is a multiple of X
	# and you can fit a linear xomino on the board

	# Then there exists a relationship between the short dimension of the board and the largest shortest dimension of the Xomino
	# if R < shortest dimension of any xomino or C < shortest dimension of any xomino: return 'RICHARD'

	# In the case of a xomino of x = keys of OminoCode, the short dimension of the borad must be at least the associated value + 1. 
	OminoCode = {3: 2, 4: 2, 5: 3, 6: 3}

	if min(R,C) < 1 + OminoCode[X]: return 'RICHARD'

	return 'GABRIEL'


main()

