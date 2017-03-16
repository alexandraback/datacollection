board = []

def printSolution(test_case, possible=False, board=None):
	if not possible:
		print "Case #{}:\nImpossible".format(t+1)
	if possible and board:
		board[0][0] = 'c'
		print "Case #{}:\n{}".format(t+1, '\n'.join([''.join(r) for r in board]))


with open('minesweeper.in', 'r') as f:
	test_cases = int(f.readline().strip())
	for t in xrange(test_cases):
		board = []
		rows, columns, mines = map(int, f.readline().strip().split())
		not_mines = rows*columns - mines
		for r in xrange(rows):
			board.append(['.' for c in xrange(columns)])

		if mines == 0:
			printSolution(t, True, board)
			continue
		
		if not_mines == 1:
			for r in xrange(rows):
				for c in xrange(columns):
					board[r][c] = '*'
			printSolution(t, True, board)
			continue

		if rows == 1:
			for i in xrange(columns-1, columns-mines-1, -1):
				board[0][i] = '*'
			printSolution(t, True, board)
			continue
				
		if columns == 1:
			for i in xrange(rows-1, rows-mines-1, -1):
				board[i][0] = '*'
			printSolution(t, True, board)
			continue
		
		while mines:
			#print '\n'.join([' '.join(r) for r in board])
			#print '\n'
			# this should actually mean rows == 2 or columns == 2
			if rows < 3 or columns < 3:
				if not_mines >= 4 and not_mines % 2 == 0:
					if rows == 2:
						for c in xrange(columns-1, not_mines/2 - 1, -1):
							board[0][c] = '*'
							board[1][c] = '*'
					elif columns == 2:
						for r in xrange(rows-1, not_mines/2 - 1, -1):
							board[r][0] = '*'
							board[r][1] = '*'
					printSolution(t, True, board)
					break
				else:
					printSolution(t, False)
					break

			if mines < min(rows, columns):
				if rows != columns:
					if rows > columns:
						for r in xrange(rows-1, rows-mines-1, -1):
							board[r][columns-1] = '*'
					else:
						for c in xrange(columns-1, columns-mines-1, -1):
							board[rows-1][c] = '*'

					printSolution(t, True, board)
					break

				if rows != 3:
					# aggiungi una di qua e una di la
					for r in xrange(rows-1, max(rows-1-mines, 1), -1):
						board[r][columns-1] = '*'
					if (mines == rows-1): board[rows-1][columns-2] = '*'
					printSolution(t, True, board)
					break
				if mines == 1:
					board[rows-1][columns-1] = '*'
					printSolution(t, True, board)
					break

				printSolution(t, False)
				break

			else: # keep goin
				if rows >= columns:
					for col in xrange(columns):
						board[rows-1][col] = '*'
					mines -= columns
					rows -= 1
				else:
					for row in xrange(rows):
						board[row][columns-1] = '*'
					mines -= rows
					columns -= 1
		else:
			if mines > 0:
				print 'Something strange has happened'
			else:
				printSolution(t, True, board)
