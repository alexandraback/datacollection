import sys

def solveThis( datafile ):
	numTests = int( datafile.readline() )

	rows = 0
	cols = 0
	mines = 0

	for case in range(1,numTests+1):
		line = datafile.readline()
		
		line = line.strip()
		line = line.split()
		rows = int( line[0] )
		cols = int( line[1] )
		mines = int( line[2] )
		
		answer = calculate( rows, cols, mines )
		
		output( answer, case )
		
		if answer != None:
			if not popcount( answer, mines ):
				sys.exit( "Not enough mines!" )


def calculate( rows, cols, mines ):

	# count empty instead
	available = rows*cols - mines
	
	# None for a c, False for a mine, and true for empty
	matrix = [[False]*cols for i in range(rows) ]
	
	if available == 1:
		matrix[0][0] = None
		return matrix
	
	
	placed = 0
	# single file gets special treatment
	if rows == 1:
		
		# can't start
		if  available!=1 and mines>0 and not available>=2 :
			return None
			
		# fill the row
		while placed < available:
			matrix[0][placed] = True
			placed = placed+1
			
			# single column same
	elif cols == 1:
	
		# can't start
		if available!=1 and mines>0 and not available>=2:
			return None
			
		# fill column
		while placed < available:
			matrix[placed][0] = True
			placed = placed+1
			
		# at least 2by2
	else:
		# try to place correctly
		matrix = place( matrix, available, rows, cols )
			
	if matrix != None:
		matrix[0][0] = None
	return matrix
		
def place( mat, nr, rows, cols  ):
	
	# we start here, cheapest
	mat[0][0] = None
	mat[0][1] = True
	mat[1][0] = True
	mat[1][1] = True
	
	nr = nr-4
	
	# if we couldn't start
	if nr<0:
		return None
		
	rind = 2
	cind = 2
	placeable = True
	
	# keep placeing all empty squares
	while nr > 0:
	
		# If we can place a pair in the edges
		if nr>=2 and placeable:
		
			# try a new row
			if rind<cind and rind<rows:
				mat[rind][0] = True
				mat[rind][1] = True
				rind = rind+1
				nr = nr-2
				
				# or along the columns
			elif cind<cols:
				mat[0][cind] = True
				mat[1][cind] = True
				cind = cind+1
				nr = nr-2
				
			elif rind<rows:
				mat[rind][0] = True
				mat[rind][1] = True
				rind = rind+1
				nr = nr-2
				
				# if we've reached both ends
			else:
				placeable = False
				
		# if doubles done		
		else:
			if nr==0:
				return mat
			
			# if 2byN, then we can't have uneven
			if rows==2 or cols==2:
				return None
				
			# if not placed new beginning
			if rind==2 or cind==2:
				return None
			
			# start filling the rest one by one	
			rsing = 2
			csing = 2
			while nr>0:
			
				# place a empty
				mat[rsing][csing] = True
				nr = nr-1
				csing = csing+1
				
				# move forward correctly, and end if full
				if csing>=cind:
					rsing = rsing+1
					csing = 2
				if rsing>=rind and nr!=0:
					return None
				
	return mat
	
def popcount( mat, mines ):
	tot = 0
	for row in mat:
		for col in row:
			if col==False:
				tot = tot+1
	return tot==mines

def output( solution, case ):
	print( "Case #{:d}:".format( case ) ) 
	if solution == None:
		print( "Impossible" )
	else:
		string = ""
		char = ''
		for row in solution:
			string = ""
			for c in row:
				if c == None:
					char = 'c'
				elif c == True:
					char = '.'
				elif c == False:
					char = '*'
					
				string = string+ char 
			print( string )
			
				
if len(sys.argv) != 2 :
	sys.exit( "Give correct files!" )

try:
	data = open( sys.argv[1], "r" )
except IOError:
	sys.exit( "Couldn't open file!" )
	
solveThis( data )

data.close()