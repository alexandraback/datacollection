def is_board_full(game):
	for row in game:
		if '.' in row:
			return False
	return True
	
def check_row(game, symbol, row): 
	row = game[row]
	
	if symbol == 'O':
		opp_symbol = 'X'
	else:
		opp_symbol = 'O'
		
	if opp_symbol in row:
		return False
	if '.' in row:
		return False
	return True
	
def check_col(game, symbol, col):
	if symbol == 'O':
		opp_symbol = 'X'
	else:
		opp_symbol = 'O'
		
	for row in game:
		if row[col] == opp_symbol:
			return False
		if row[col] == '.':
			return False
	return True
	
def check_diag(game, symbol):
	if symbol == 'O':
		opp_symbol = 'X'
	else:
		opp_symbol = 'O'
	
	for mode in [1,2]:
		win = True
		for i in xrange(0,4):
			if mode == 1:
				row = i
				col = i
			else:
				row = i
				col = 3 - i
			if game[row][col] == opp_symbol:
				win = False
				break
			if game[row][col] == '.':
				win = False
				break
		if win == True:
			return True
	return False		

num_test_cases = int(raw_input()) + 1

for num in xrange(1,num_test_cases):
	game = []
	for row in xrange(0,4):
		game.append(list(raw_input().strip()))
	
	outcome = ""

	for i in xrange(0, 4):
		if check_row(game, 'X', i) == True:
			if num == 8:
				print 'here', i
				print game
			outcome = "X won"
			break
		elif check_row(game, 'O', i) == True:
			outcome = "O won"
			break
	
	if outcome == "":
		for j in xrange(0,4):
			if check_col(game, 'X', j) == True:
				outcome = "X won"
				break
			elif check_col(game, 'O', j) == True:
				outcome = "O won"
				break
	
	if outcome == "":
		if check_diag(game, 'X') == True:
			outcome = "X won"
		elif check_diag(game, 'O') == True:
			outcome = "O won"
		elif is_board_full(game) == True:
			outcome = "Draw"
		else:
			outcome = "Game has not completed"
	
	print "Case #%s: %s" % (num, outcome)
	if num < num_test_cases - 1:
		raw_input()