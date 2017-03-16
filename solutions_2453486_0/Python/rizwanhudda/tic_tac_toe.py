def isFilled(s, peice):
	return s.count(peice) + s.count('T') == 4

def isWinner(board, peice):
	tl_br = ''
	bl_tr = ''
	for i in range(4):
		ir = board[i]
		ic = ''.join(map(lambda x: x[i], board))
		if isFilled(ir, peice) or isFilled(ic, peice):
			return True
		tl_br += board[i][i]
		bl_tr += board[i][3-i]
	return isFilled(tl_br, peice) or isFilled(bl_tr, peice)

t = input()
for case_no in range(1, t+1):
	board = []
	for i in range(4): board.append(raw_input())
	print 'Case #%d:'  % case_no,
	if isWinner(board, 'X'):
		print 'X won'
	elif isWinner(board, 'O'):
		print 'O won'
	elif  ''.join(board).count('.') == 0:
		print 'Draw'
	else:
		print 'Game has not completed'
	raw_input() # discard empty line