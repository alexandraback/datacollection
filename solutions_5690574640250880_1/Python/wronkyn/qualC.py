#!/usr/bin/python

import sys

def toggleIfPositive(board, row, column, blanks):
	if board[row][column] == '*' and blanks[0] > 0:
		board[row][column] = '.'
		blanks[0] -= 1

def testCase(case, _rows, _columns, blanks):
	# assume that rows <= columns
	rows = min(_rows, _columns)
	columns = max(_rows, _columns)

	board = []
	for i in range(rows):
		board.append(['*'] * columns)
	board[0][0] = 'c'

	possible = True

	if blanks == 1: #just do the corner
		None

	elif blanks == 4: #corner also
		if rows > 1:
			board[1][1] = board[0][1] = board[1][0] = '.'
		else:
			for i in range(1, blanks):
				board[0][i] = '.'

	elif blanks < 6 or blanks == 7: # 2, 3, 5, 7
		if rows > 1:
			possible = False
		else:
			for i in range(1, blanks):
				board[0][i] = '.'
	
	else: # 6, or at least 8 blanks
		if rows == 1:
			for i in range(1, blanks):
				board[0][i] = '.'
		elif rows == 2 or blanks == 6:
			if (blanks % 2) == 1:
				possible = False
			else:
				board[1][0] = '.'
				for i in range(1, blanks/2):
					board[0][i] = board[1][i] = '.'
		else: # at least 3 rows
			board[1][0] = board[2][0] = board[0][1] = board[1][1] = board[2][1] = board[0][2] = board[1][2] = '.'
			blanks -= 8
			if (blanks % 2) == 1:
				board[2][2] = '.'
				blanks -= 1

			blanks = [blanks]
			for row in range(rows):
				toggleIfPositive(board, row, 0, blanks)
				toggleIfPositive(board, row, 1, blanks)
			for column in range(columns):
				toggleIfPositive(board, 0, column, blanks)
				toggleIfPositive(board, 1, column, blanks)

			for row in range(rows):
				for column in range(columns):
					toggleIfPositive(board, row, column, blanks)

	if (_rows > _columns):
		board = [list(i) for i in zip(*board)]


	print "Case #{}:".format(case)

	if possible:
		for i in range(len(board)):
			print "".join(board[i])
	else:
		print "Impossible"

if __name__ == "__main__":
	testCases = int(sys.stdin.readline())

	for i in range(1, testCases + 1):
		params = [int(k) for k in sys.stdin.readline().split()]
		testCase(i, params[0], params[1], params[0]*params[1] - params[2])
		
else:
	print "not main"
