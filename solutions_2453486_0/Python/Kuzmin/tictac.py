lines = open("tic-small.in").readlines()

T = int(lines.pop(0))

cases = [lines[(i*5):(i+1)*5-1] for i in range(0, T)]

d = {'X': 1, 'O': -1, '.': 0, 'T': 100}

def parseCase(case):
	return [map(lambda x: d[x], c[0:4]) for c in case]

def isWinner(s, i):
	if s == 4 or s == 103:
		winner = "X"
	elif s == -4 or s == 97:
		winner = "O"
	else:
		return False
	
	print( "Case #%s: %s won" % (str(i+1), winner) )
	return True

def testCase(i, case):
	# Test rows
	for row in case:
		s = sum(row)

		if isWinner(s, i):
			return
	
	# Test columns
	for j in range(0,4):
		s = sum(case[x][j] for x in range(0,4))

		if isWinner(s, i):
			return 
	
	# Diagonals
	sums = [sum(case[j][j] for j in range(0,4)), sum(case[j][-j-1] for j in range(0,4))]
	for s in sums:
		if isWinner(s, i):
			return 

	#Draw or game going on
	zeroes = False
	for row in case:
		for e in row:
			if e == 0:
				zeroes = True

	if zeroes:
		end = "Game has not completed"
	else:
		end = "Draw"

	print("Case #%s: %s" % (i+1, end))


for i in range(0, T):
	case = parseCase(cases[i])
	
	testCase(i, case)
