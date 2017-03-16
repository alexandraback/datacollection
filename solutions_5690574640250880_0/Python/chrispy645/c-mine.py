from sys import stdin
import sys
import random
import time
import math

#random.seed(10)

num_cases = int(stdin.readline().rstrip())

def print_board(board):	
	for b in board:
		print ''.join(b)
		
def check_adj(board,i,j):

	mine_count = 0
	# i = row, j = col
	
	cfgs = [ [i-1,j-1], [i-1,j], [i-1,j+1], [i,j-1], [i,j+1], [i+1,j-1], [i+1,j], [i+1,j+1] ]
	
	for c in cfgs:
		try:
			if c[0] >= 0 and c[1] >= 0:
				if board[ c[0] ][ c[1] ] == '*':
					mine_count += 1
		except:
			continue
			
	#board[i][j] = str(mine_count)
	return mine_count
		
	
def recurse_check(board,i,j,seen):

	if i < 0 or j < 0:
		return
	if board[i][j] == '*':
		return
	key = str(i) + "," + str(j)
	if key in seen and seen[key] == True:
		return


	cfgs = [ [i-1,j-1], [i-1,j], [i-1,j+1], [i,j-1], [i,j+1], [i+1,j-1], [i+1,j], [i+1,j+1] ]
	
	board[i][j] = str( check_adj(board, i, j) )	
	seen[key] = True
	

	
	# if there is a 0, recursively do this!
	if check_adj(board, i, j) == 0:
		for c in cfgs:
			try:
				recurse_check(board, c[0], c[1], seen)
			except:
				continue
			

			
			
def deepcopy(board):
	new_board = []
	for i in range(0, len(board)):
		new_board.append( list(board[i]) )
	return new_board
	
def check_complete(board):
	dot_count = 0
	for i in range(0, len(board)):
		for j in range(0, len(board[i])):
			if board[i][j] == '.':
				dot_count += 1
	return dot_count

	
"""
Doesn't guarantee to add the number of dots you say it's
going to add.
"""
def add_dots(board,v,w,num_dots):
	square_num_dots = int(math.sqrt(num_dots))
	count = 0
	for m in range(0, min(square_num_dots+v,rows)):
		for n in range(0, min(square_num_dots+w, cols)):
			if count != num_dots:
				board[m][n] = '.'
				count += 1
	return count
	
def add_dots_2(board,v,w,num_dots):
	square_num_dots = int(math.sqrt(num_dots))
	count = 0
	for n in range(0, min(square_num_dots+w, cols)):
		for m in range(0, min(square_num_dots+v,rows)):
			if count != num_dots:
				board[m][n] = '.'
				count += 1
	return count
	
def add_mines(board,v,w,num_mines):
	square_num_mines = int(math.sqrt(num_mines))
	count = 0
	for m in range(0, min(square_num_mines+v,rows)):
		for n in range(0, min(square_num_mines+w, cols)):
			if count != num_mines:
				board[m][n] = '*'
				count += 1
	return count
	
def add_mines_2(board,v,w,num_mines):
	square_num_mines = int(math.sqrt(num_mines))
	count = 0
	for n in range(0, min(square_num_mines+w, cols)):
		for m in range(0, min(square_num_mines+v,rows)):
			if count != num_mines:
				board[m][n] = '*'
				count += 1
	return count
	
def is_possible(board):
	for i in range(0, rows):
		for j in range(0, cols):
			newboard = deepcopy(board)
			recurse_check(newboard,i,j,dict())
			
			result = check_complete(newboard)
			#print_board(newboard)
			#print
			if result == 0:
				board[i][j] = 'c'
				return True
				
	return False
			
for z in range(0, num_cases):

	preboard = []
	preboard_dots = []
	
	st = stdin.readline().rstrip().split()
	st = [int(x) for x in st]
	
	rows = st[0]
	cols = st[1]
	num_mines = st[2]
	
	for i in range(0, rows):
		preboard.append( ['*' for j in range(0, cols) ] )
		preboard_dots.append( ['.' for j in range(0, cols) ] )

	

	num_dots = (rows*cols) - num_mines
	
	result = None
	finish=False
	for v in range(0,rows):
		for w in range(0,cols):
			board = deepcopy(preboard)
			result = add_dots(board, v, w, num_dots)
			if result == num_dots:
				result = is_possible(board)
				#print_board(board)
				#print
				if result == True:
					finish = True
					break
					
			board = deepcopy(preboard)
			result = add_dots_2(board, v, w, num_dots)
			if result == num_dots:
				result = is_possible(board)
				#print_board(board)
				#print
				if result == True:
					finish = True
					break
					
			board = deepcopy(preboard_dots)
			result = add_mines(board, v, w, num_mines)
			if result == num_mines:
				result = is_possible(board)
				#print_board(board)
				#print
				if result == True:
					finish = True
					break
					
			board = deepcopy(preboard_dots)
			result = add_mines_2(board, v, w, num_mines)
			if result == num_mines:
				result = is_possible(board)
				#print_board(board)
				#print
				if result == True:
					finish = True
					break	
			
				
		if finish == True:
			break
			
	print "Case #" + str(z+1) + ":"
	if result == False:
		print "Impossible"
		#print_board(board) # remove!!!
	else:
		print_board(board)
			
	#sys.exit(0)