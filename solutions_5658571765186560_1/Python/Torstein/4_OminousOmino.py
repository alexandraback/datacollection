# Google Codejam 2015 Qualifier
# Ominous Omino
canObstruct = "RICHARD"
canPlace = "GABRIEL"

def canPickObscurePiece(X, rows, cols):
	## Ensure less rows than cols
	rw = min(rows, cols)
	cl = max(rows, cols)
	## Pick longest guy if this wins
	if cl < X:
		return True
	if rw < (X+1)/2:
		return True
	## Cannot win if height is higher than minimum brick height
	if rw > (X+1)/2:
		return False
	## Create piece - smallest side must have height rw
	## Then maxwidth is X-height+1
	height = rw
	maxwidth = X-height+1
	## in the maxwidth x height grid, we can choose how
	## many to leave on either side  1,2, ... gridsize-X
	## for each choice, move the grid along the band to
	## ensure every position will be impossible
	for lspace in xrange(height*maxwidth-X):
		rspace = height*maxwidth-X-lspace
		placepossible = False
		for gridpos in xrange(cl-maxwidth):
			leftside = gridpos*rw+lspace
			rightside = rw*(cl-gridpos-maxwidth)+rspace
			if leftside % X == 0 and rightside % X == 0:
				placepossible = True
		if not placepossible:
			return True
	return False
	



testcases = int(raw_input().strip())
for testcase in xrange(testcases):
	X, rows, cols = map(int, raw_input().split())
	winner = canPlace
	## Case 1: Wrong dimension on board
	if (rows*cols) % X != 0:
		winner = canObstruct
	## Case 2: Can pick tile with hole
	elif X >= 7:
		winner = canObstruct
	## Case 3: Piece will make wrongsized hole with
	##         edge of board regardless of placement
	elif canPickObscurePiece(X, rows, cols):
		winner = canObstruct
	print "Case #%d:" % (testcase+1), winner
