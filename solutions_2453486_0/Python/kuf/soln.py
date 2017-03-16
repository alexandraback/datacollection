import sys

def checkSoln(generator):
	each = None
	for x in generator:
		if x is not '.':
			if x is 'T':
				continue
			elif not each:
				each = x
			elif x is not each:
				return None
		else:
			return x
	return each

def diagonalFromTopLeft(board):
	return (board[i][i] for i in range(4))

def diagonalFromBottomLeft(board):
	return (board[-(i+1)][i] for i in range(4))

def vertical(board,i):
	return (board[j][i] for j in range(4))

def horizontal(board, i):
	return (board[i][j] for j in range(4))

def allSolns(board):
	seenEmpty = False
	diagonals = [diagonalFromTopLeft,diagonalFromBottomLeft]
	for func in diagonals:
		x = checkSoln(func(board))
		if x is '.':
			seenEmpty = True
		elif x:
			return x

	vertAndHorizont = [vertical,horizontal]
	for i in range(4):
		for func in vertAndHorizont:
			x = checkSoln(func(board,i))
			if x is '.':
				seenEmpty = True
			elif x:
				return x

	return seenEmpty

def readlineIn():
	theFile = open("A-small-attempt1.in")
	N = int(theFile.readline().strip())
	valid = ['O','X']
	for k in range(N):
		board =[list(theFile.readline().strip()) for x in range(4)]
		theFile.readline()
		result = allSolns(board)
		if result is True:
			print "Case #%d: Game has not completed" % (k+1)
		elif result is False:
			print "Case #%d: Draw" % (k+1)
		elif result in valid:
			print "Case #%d: %s won" % (k+1,result)
	print

readlineIn()