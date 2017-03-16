import sys
n_cases = input()
case = 1
def solve():
	board = [raw_input() for i in range(4)]
	try:
		raw_input()
	except EOFError:
		pass
	for player in 'OX':
		good = player + 'T'
		
		d1 = True
		d2 = True
		for i in range(4):
			if not board[i][i] in good:
				d1 = False
			if not board[i][3-i] in good:
				d2 = False
		if d1 or d2:
			return player + ' won'
		
		for i in range(4):
			h = v = True
			for j in range(4):
				if not board[i][j] in good:
					h = False
				if not board[j][i] in good:
					v = False
			if h or v:
				return player + ' won'
	if '.' in ''.join(board):
		return 'Game has not completed'
	else:
		return 'Draw'

for case in range(1,n_cases+1):
	print 'Case #'+`case`+': '+solve()