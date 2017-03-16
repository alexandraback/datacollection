import sys
from pprint import pprint
file="A"
file = sys.argv[1]

lines = open(file).readlines()
N = int(lines[0])

currentLine = 1

def eval(row, column, grid, R, C):

	if row + 1 <= R - 1:
		if column + 1 <= C - 1:
			if grid[row + 1][column + 1] != '*':
				return False
		if column - 1 >= 0:
			if grid[row + 1][column - 1] == '*':
				return False
		if grid[row + 1][column] == '*':
			return False

	if column + 1 <= C - 1:
		if grid[row][column + 1] == '*':
			return False
	if column - 1 >= 0:
		if grid[row - 1][column - 1] == '*':
			return False
		
	if row - 1 >= 0:
		if column + 1 <= C - 1:
			if grid[row - 1][column + 1] == '*':
				return False
		if column - 1 >= 0:
			if grid[row - 1][column - 1] == '*':
				return False
		if grid[row - 1][column] == '*':
			return False
	return True



for case in range(N):
	R,C,M = map(int, lines[currentLine].split())
	#print " ".join(map(str,[R,C,M]))
	currentLine = currentLine + 1
	if (R == 1):
	 	if R * C - M < 1:
			print "Case #{}:\nImpossible".format(case + 1)
		else:
			blanks = R*C - M - 1
			grid = "".join(['c'] + ['.' for x in xrange(blanks)] + ['*' for x in xrange(M)])
			print "Case #{}:\n{}".format(case + 1, grid)
	elif C == 1:		
	 	if R * C - M < 1:
			print "Case #{}:\nImpossible".format(case + 1)
		else:
			blanks = R*C - M - 1
			grid = "\n".join(['c'] + ['.' for x in xrange(blanks)] + ['*' for x in xrange(M)])
			print "Case #{}:\n{}".format(case + 1, grid)					
	elif R * C - M == 1:
		grid = [['*' for x in xrange(C)] for x in xrange(R)]
		grid[0][0] = 'c'
		printgrid = '\n'.join(["".join(x) for x in grid])
		print "Case #{}:\n{}".format(case + 1 ,printgrid)
	elif R * C - M < 4:
		print "Case #{}:\nImpossible".format(case + 1)
	else:
		grid = [['*' for x in xrange(C)] for x in xrange(R)]
		blanks = R*C - M - 4
		grid[0][0] = 'c'
		grid[0][1] = '.'
		grid[1][0] = '.'
		grid[1][1] = '.'
		
		
		for column in range(2,C):
			if blanks == 3:
				break
			if blanks > 1:
				grid[0][column] = '.'
				blanks -= 1
				grid[1][column] = '.'
				blanks -= 1				

		for row in range(2,R):
			if blanks > 1:
				grid[row][0] = '.'
				blanks -= 1
				grid[row][1] = '.'
				blanks -= 1

		superbreak = 0
		for column in range(2,C):
			for row in range (2, R):
				if blanks > 0:
					if(eval(row-1, column-1, grid, R, C)):
						grid[row][column] = '.'
						blanks -=1
					else:
						print "Case #{}:\nImpossible".format(case + 1)
						superbreak = 1
						break;
			if superbreak == 1:
				break;
		else:
			if blanks > 0:
				print "Case #{}:\nImpossible".format(case + 1)
			else:
				printgrid = '\n'.join(["".join(x) for x in grid])
				print "Case #{}:\n{}".format(case + 1 ,printgrid)
