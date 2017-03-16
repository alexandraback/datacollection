def checkBoard(board):
	for row in range(4):
		Xwon = True
		for column in range(4):
			if board[row][column] == 'O' or board[row][column] == '.':
				Xwon = False
				break
		if Xwon == True:
			return 'X won'
		Owon = True
		for column in range(4):
			if board[row][column] == 'X' or board[row][column] == '.':
				Owon = False
				break
		if Owon == True:
			return 'O won'

	for column in range(4):
		Xwon = True
		for row in range(4):
			if board[row][column] == 'O' or board[row][column] == '.':
				Xwon = False
				break
		if Xwon == True:
			return 'X won'
		Owon = True
		for row in range(4):
			if board[row][column] == 'X' or board[row][column] == '.':
				Owon = False
				break
		if Owon == True:
			return 'O won'
	
	Xwon = True
	for rc in range(4):
		if board[rc][rc] == 'O' or board[rc][rc] == '.':
			Xwon = False
			break
	if Xwon == True:
		return 'X won'
	Owon = True
	for rc in range(4):
		if board[rc][rc] == 'X' or board[rc][rc] == '.':
			Owon = False
			break
	if Owon == True:
		return 'O won'

	Xwon = True
	for rc in range(4):
		if board[rc][3 - rc] == 'O' or board[rc][3 - rc] == '.':
			Xwon = False
			break
	if Xwon == True:
		return 'X won'
	Owon = True
	for rc in range(4):
		if board[rc][3 - rc] == 'X' or board[rc][3 - rc] == '.':
			Owon = False
			break
	if Owon == True:
		return 'O won'

	for row in range(4):
		for column in range(4):
			if board[row][column] == '.':
				return 'Game has not completed'

	return 'Draw'

T = int(raw_input())
for t in range(T):
	if t > 0:
		dummy = raw_input()
	board = []
	for row in range(4):
		line = raw_input()
		board.append(line)
	print 'Case #' + str(t + 1) + ':', checkBoard(board)
