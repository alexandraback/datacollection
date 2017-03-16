def state(board):
	board_filled = True
	t=-1
	t_i=-1
	for i in range(4):	
		if "." in board[i]:
			board_filled = False
	for i in range(4):	
		t = board[i].find('T')
		if t != -1:			
			t_i = i
			break
	#X round
	if t != -1:
		board[t_i] = board[t_i][:t] + 'X' + board[t_i][t+1:]
	for i in range(4):		
		if board[i] == "XXXX\n":
			return "X won"
		if board[0][i] == 'X' and board[1][i] == 'X' and board[2][i] == 'X' and board[3][i] == 'X':
			return "X won"
	if board[0][0] == 'X' and board[1][1] == 'X' and board[2][2] == 'X' and board[3][3] == 'X':
		return "X won"
	if board[0][3] == 'X' and board[1][2] == 'X' and board[2][1] == 'X' and board[3][0] == 'X':
		return "X won"
	#O round
	if t != -1:
		board[t_i] = board[t_i][:t] + 'O' + board[t_i][t+1:]
	for i in range(4):		
		if board[i] == "OOOO\n":
			return "O won"
		if board[0][i] == 'O' and board[1][i] == 'O' and board[2][i] == 'O' and board[3][i] == 'O':
			return "O won"
	if board[0][0] == 'O' and board[1][1] == 'O' and board[2][2] == 'O' and board[3][3] == 'O':
		return "O won"
	if board[0][3] == 'O' and board[1][2] == 'O' and board[2][1] == 'O' and board[3][0] == 'O':
		return "O won"
	
	if board_filled:
		return "Draw"
	return "Game has not completed"


#print state(["XXXX","XXXX","OOTO","..X."])
f = open("A-large.in")
g = open("Output.txt", 'w')
cases = int(f.readline())
for case in range(cases):
	board = ["", "", "", ""]
	for i in range(4):	
		board[i] = f.readline()
	result = state(board)
	g.write("Case #" + str(case+1) + ": " + result + "\n")
	f.readline()
