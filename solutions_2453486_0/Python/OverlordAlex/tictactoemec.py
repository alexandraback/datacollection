cases = int(raw_input())

for case in range(cases):
	board = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
	emptyspace = False
	won = False
	for i in range(4):
		line = raw_input()
		for c in range(4):
			board[i][c] = line[c]
			if line[c]==".":
				emptyspace=True
	line = raw_input() # read the final blank line
	
	xdiagleft = 0
	xdiagright = 0
	odiagleft = 0
	odiagright = 0
	for i in range(4):
		if (won): break
		xcounthoz = 0
		ocounthoz = 0
		xcountvert = 0
		ocountvert = 0
		for j in range(4):
			xcounthoz += 1 if board[i][j]=='X' or  board[i][j]=='T' else 0
			ocounthoz += 1 if board[i][j]=='O' or  board[i][j]=='T' else 0
			xcountvert += 1 if board[j][i]=='X' or  board[j][i]=='T' else 0
			ocountvert += 1 if board[j][i]=='O' or  board[j][i]=='T' else 0
		
		if (xcounthoz == 4) or (xcountvert == 4):
			print "Case #"+str(case+1)+": X won"
			won = True
			break
		if (ocounthoz == 4) or (ocountvert == 4):
			print "Case #"+str(case+1)+": O won"
			won = True
			break
			
		if (board[i][i]=='X') or (board[i][i]=='T'):
			xdiagleft += 1
		if (board[i][i]=='O') or (board[i][i]=='T'):
			odiagleft += 1
		
		if (board[3-i][i]=='X') or (board[3-i][i]=='T'):
			xdiagright += 1
		if (board[3-i][i]=='O') or (board[3-i][i]=='T'):
			odiagright += 1
	
	if (xdiagleft == 4) or (xdiagright == 4) and (not won):
		print "Case #"+str(case+1)+": X won"
		won = True
	if (odiagleft == 4) or (odiagright == 4) and (not won):
		print "Case #"+str(case+1)+": O won"
		won = True

	if (not emptyspace) and (not won):
		print "Case #"+str(case+1)+": Draw"
	elif (emptyspace) and (not won):
		print "Case #"+str(case+1)+": Game has not completed" 
			
	
