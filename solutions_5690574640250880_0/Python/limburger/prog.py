import sys
import copy

def convertBoard( board ):
	board_text = ""
	for r in range(len(board)):
		board_text += "".join( board[r] )
		board_text += "\n"
		
	return board_text.strip()

def overlayCost( board, square ):
	#check surrounding squares to see if they would change from mine to free
	#if you were to overlay there
	cost = 0
	
	#print( "overlayCost - square{}\n".format( square ) )
	
	for tr in range( square[0] - 1, square[0] + 2 ):
		for tc in range( square[1] -1, square[1] + 2 ):
		
			if tr < 0 or tc < 0:
				continue
			
			if( tr >= len( board ) or tc >= len( board[0] ) ):
				continue
				
			
			#print( "tr: {} tc: {} value: {}\n".format( tr, tc, board[tr][tc] ) )
			
			if board[tr][tc] == "*":
				cost += 1
				
	return cost

def overlayBoard( board, square):
	
	new_board = copy.deepcopy( board )
	
	for tr in range( square[0] - 1, square[0] + 2 ):
		for tc in range( square[1] -1, square[1] + 2 ):
			if tr < 0 or tc < 0:
				continue
			
			if( tr >= len( new_board ) or tc >= len( new_board[0] ) ):
				continue
			
			if new_board[tr][tc] == "*":
				new_board[tr][tc] = "."
				
	return new_board
			
	
def overlayBorders( board, borders, square ):
	new_borders = copy.deepcopy( borders )
	new_borders.remove( square )
	
	for tr in range( square[0] - 1, square[0] + 2 ):
		for tc in range( square[1] -1, square[1] + 2 ):
			if tr < 0 or tc < 0:
				continue
			
			if( tr >= len( board ) or tc >= len( board[0] ) ):
				continue
			
			if board[tr][tc] == "*":
				new_borders.append( [tr,tc] )
				
	return new_borders

def computeBoardHelper( board, borders, remaining ):

	#print( "cbh\n" + convertBoard( board ) )
	#print( "remaining: {}\n".format( remaining ) )
	#input()
	
	if remaining == 0:
		return convertBoard( board )
		
	for b in borders:
	
		cost = overlayCost( board, b )
		
		#print( "border: {} cost: {}\n".format( b, cost ) )
		
		if cost > remaining or cost == 0:
			continue
			
		answer = computeBoardHelper( overlayBoard( board, b ), overlayBorders( board, borders, b ), remaining - cost )
		
		if answer == "Impossible":
			continue
		else:
			return answer
	
	return "Impossible"
		

def computeBoard( rows, cols, mines ):
	#only get here if there are more than 4 free squares
	board_rows = []
	borders = []
	for r in range(rows):
		board_cols = []
		for c in range(cols):
			if r == 1 or c == 1:
				borders.append( [r,c] )
				
			if r == 0 and c == 0:
				board_cols.append( "c" )
				continue
				
			if r < 2 and c < 2:
				board_cols.append( "." )
				continue
				
			board_cols.append( "*" )
			
		board_rows.append( board_cols )
		
	free = 4
	remaining = ( rows * cols ) - mines - free
	return computeBoardHelper( board_rows, borders, remaining )		
		

def generateBoard( rows, cols, click, mines ):
	board = ""
	
	for r in range(rows):
		for c in range(cols):
			if( [r, c] == click ):
				board += "c"
			elif( [r,c] in mines ):
				board += "*"
			else:
				board += "."
				
		board += "\n"
		
	return board.strip()

def solveGame(rows, cols, mine_count):
	if( mine_count == 0 ):
		return generateBoard( rows, cols, [0,0], [] )
	
	free = rows * cols - mine_count
	
	if( free == 1 ):
		mines = []
		for r in range(rows):
			for c in range(cols):
				if( c == 0 and r == 0 ):
					continue
					
				mines.append( [r,c] )
				
		return generateBoard( rows, cols, [0,0], mines )
	
	if( rows == 1 or cols == 1 ):
		mines = []
		free_left = free
		for c in range(cols):
			for r in range(rows):
				if( c == 0 and r == 0 ):
					free_left -= 1
					continue
					
				if( free_left > 0 ):
					free_left -= 1
					continue
					
				mines.append( [r, c] )
				
		return generateBoard( rows, cols, [0,0], mines )

	if( free >=2 and free < 4 ):
		return "Impossible"
		
	if( free == 4 ):
		mines = []
		for r in range(rows):
			for c in range(cols):
				if r == 0 and c == 0:
					continue
					
				if r < 2 and c < 2:
					continue
					
				mines.append( [r,c] )
				
		return generateBoard( rows, cols, [0,0], mines )
	
	if( ( rows == 2 or cols == 2 ) and ( (free % 2) == 1 ) ):
		return "Impossible"
		
	return computeBoard( rows, cols, mine_count )
	
def solve(infile):
	output = ""
	t_count = int( infile.readline() )
	
	for t in range( t_count ):
		print( "*** Test Case {}***".format( t+1 ) )
		
		parts = infile.readline().strip().split(" ")
		(rows, cols, mine_count) = [int(x) for x in parts]
		answer = solveGame( rows, cols, mine_count )
		output += "Case #{}:\n{}\n".format( t+1, answer )
		
	return output.strip()

if( __name__ == "__main__" ):
	infile_name = sys.argv[1]
	
	output = "__null__"
	with open( infile_name ) as f:
		output = solve( f )
		
	with open( infile_name + ".out", "w" ) as of:
		of.write( output )
	
	exit(0)