def validColumn(j,item,board):
	for x in (row[j] for row in board):
		if item < x:
			return False
	return True

def validRow(j,item,board):
	for x in board[j]:
		if item < x:
			return False
	return True

def run(board):
	for i,row in enumerate(board):
		for j,item in enumerate(row):
			if item == 1:
				valCol = validColumn(j,item,board)
				valRow = validRow(i,item,board)
				if not valCol and not valRow:
					raise Exception
	return True

def problem():
	theFile = open("B-small-attempt0.in")
	N = int(theFile.readline())
	for k in range(N):
		rows,cols = [int(x) for x in theFile.readline().split(' ')]
		board = []
		for x in range(rows):
			row = [int(x) for x in theFile.readline().split(' ')]
			board.append(row)
		try:	
			run(board)
			print "Case #%d: YES" % (k+1)
		except Exception as e:
			print "Case #%d: NO" % (k+1)
	print

problem()