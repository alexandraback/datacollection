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

def calcMaxCols(board,cols):
	return [max([row[j] for row in board]) for j in range(cols)]

def run(board,columns):
	maxCols = calcMaxCols(board,columns)
	for i,row in enumerate(board):
		maxRow = max(row)
		for j,item in enumerate(row):
			if item < maxRow or item < maxCols[j]:
				valCol = validColumn(j,item,board)
				valRow = validRow(i,item,board)
				if not valCol and not valRow:
					raise Exception
	return True

def problem():
	theFile = open("B-large.in")
	N = int(theFile.readline())
	for k in range(N):
		rows,cols = [int(x) for x in theFile.readline().split(' ')]
		board = []
		for x in range(rows):
			row = [int(x) for x in theFile.readline().split(' ')]
			board.append(row)
		try:	
			run(board,cols)
			print "Case #%d: YES" % (k+1)
		except Exception as e:
			print "Case #%d: NO" % (k+1)
	print

problem()