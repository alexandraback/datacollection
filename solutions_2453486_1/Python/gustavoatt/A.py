#!/usr/bin/env python
import sys

O_WON 		= 1
X_WON 		= 2
DRAW  		= 3
UNFINISHED 	= 4 

def analyze_board(board):
	o_won, x_won = False, False
	full_board = True

	# Rows and colums
	for i in xrange(len(board)):
		row = board[i]
		col = "".join([board[j][i] for j in xrange(len(board))])

		if row.count('.') > 0 or col.count('.') > 0:
			full_board = False

		for line in [row, col]:
			for val in ['X', 'O']:
				if line.count(val) == 4 or (line.count(val) == 3 
					and line.count('T') == 1):
					if val == 'X':
						x_won = True
					else:
						o_won = True

	# Diagonals
	r_diag = "".join([board[i][i] for i in xrange(len(board))])
	l_diag = "".join([board[i][len(board) - i - 1] for i in xrange(len(board))])
	for line in [r_diag, l_diag]:
		for val in ['X', 'O']:
			if line.count(val) == 4 or (line.count(val) == 3 and line.count('T') == 1):
				if val == 'X':
					x_won = True
				else:
					o_won = True
	

	if x_won:
		return X_WON
	elif o_won:
		return O_WON
	elif full_board:
		return DRAW
	return UNFINISHED

if __name__ == '__main__':
	T = int(sys.stdin.readline().strip())
	for CASE in xrange(1, T + 1):
		board  = [sys.stdin.readline().strip() for i in xrange(4)]
		
		result = analyze_board(board)
		if result == O_WON:
			print "Case #{}: O won".format(CASE)
		elif result == X_WON:
			print "Case #{}: X won".format(CASE)
		elif result == DRAW:
			print "Case #{}: Draw".format(CASE)
		elif result == UNFINISHED:
			print "Case #{}: Game has not completed".format(CASE)

		sys.stdin.readline()	# White line

