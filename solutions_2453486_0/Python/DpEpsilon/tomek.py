import sys

def line_winner(line):
	winner = None
	if not ('.' in line or ('X' in line and 'O' in line)):
		if 'X' in line:
			winner = 'X'
		if 'O' in line:
			winner = 'O'
	return winner

def game_finished(case):
	for row in case:
		if '.' in row:
			return False
	return True

fin = open(sys.argv[1]).readlines()
test_cases = int(fin[0])
for i in xrange(test_cases):
	fin = fin[1:]
	case = fin[:4]

	winner = None
	
	for line in case:
		winner = line_winner(line)
		if winner is not None:
			break
	

	if winner is None:
		for col in xrange(4):
			line = ""
			for row in xrange(4):
				line += case[row][col]
			winner = line_winner(line)
			if winner is not None:
				break
	
	if winner is None:
		line = ""
		for j in xrange(4):
			line += case[j][j]
		winner = line_winner(line)
	if winner is None:
		line = ""
		for j in xrange(4):
			line += case[j][3-j]
		winner = line_winner(line)

	print "Case #" + str(i+1) + ":",
	if winner == 'X':
		print "X won"
	elif winner == 'O':
		print "O won"
	else:
		if game_finished(case):
			print "Draw"
		else:
			print "Game has not completed"
	fin = fin[4:]

	
