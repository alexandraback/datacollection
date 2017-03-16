import math

def printBoard(board):
	board[0][0] = 'c'
	for i in range(len(board)):
		row = ''
		for j in range(len(board[0])):
			row += board[i][j]
		print row

def fillBoard(board, free_spaces):
	R = len(board)
	C = len(board[0])

	free_count = 0
	for dim in range(min(R, C)):
		for i in range(dim):
			board[i][dim] = '.'
			free_count+=1
			if free_count == free_spaces:
				if i == 0:
					board[1][dim] = '.'
					board[dim-1][dim-1] = '*'
				return board
		for i in range(dim):
			board[dim][i] = '.'
			free_count+=1
			if free_count == free_spaces:
				if i == 0:
					board[dim][1] = '.'
					board[dim-1][dim] = '*'
				return board
		board[dim][dim] = '.'
		free_count+=1
		if free_count == free_spaces:
			return board
	if C > R:
		for col in range(R, C):
			for row in range(R):
				board[row][col] = '.'
				free_count+=1
				if free_count == free_spaces:
					if row == 0:
						board[1][col] = '.'
						board[R-1][col-1] = '*'
					return board
	if R > C:
		for row in range(C, R):
			for col in range(C):
				board[row][col] = '.'
				free_count+=1
				if free_count == free_spaces:
					if col == 0:
						board[row][1] = '.'
						board[row-1][C-1] = '*'
					return board
	return board

T = int(raw_input())
for t in range(1, T+1):
	print "Case #%d:" % t
	R, C, M = [int(i) for i in raw_input().split()]
	board = [['*' for c in range(C)] for r in range(R)]

	# no mines are always possible
	if M == 0:
		for i in range(len(board)):
			for j in range(len(board[0])):
				board[i][j] = '.'
		printBoard(board)
		continue
	if M == C*R-1:
		printBoard(board)
		continue
	# 1xn boards are always possible
	if R == 1:
		for i in range(C-M):
			board[0][i] = '.'
		printBoard(board)
		continue
	if C == 1:
		for i in range(R-M):
			board[i][0] = '.'
		printBoard(board)
		continue
	# 2xn boards for n > 1 are impossible with an odd number of mines
	if (R == 2 or C == 2) and M % 2 == 1:
		print "Impossible"
		continue
	free_spaces = C*R - M
	if free_spaces < 4 or free_spaces == 5 or free_spaces == 7:
		print "Impossible"
		continue
	board = fillBoard(board, free_spaces)
	printBoard(board)

