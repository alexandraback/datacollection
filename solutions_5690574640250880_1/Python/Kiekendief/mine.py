import os
import sys

if len(sys.argv) > 1 :
	inputfile = sys.argv[1]
	outputfile = inputfile.split(".txt")[0]+"_output.txt"
else :
	inputfile = "input.txt"
	outputfile = "output.txt"

os.chdir(sys.path[0])

input = open(inputfile,"r")
lines = input.readlines()
input.close()

output = open(outputfile,"w")



def getMatrix (rows, cols, mines):
	mx = []
	for i in range(rows):
		row = []
		for j in range(cols):
			row.append('0')
		mx.append(row)
	
	if(rows == 1 or cols == 1):
		if (mines <  rows*cols) :	
			if(rows==1) :
				# should be one left at least
				if (mines < cols ):
					for i in range(mines) :
						mx[0][i] = '*'
					for i in range(mines, cols - 1) :
						mx[0][i] = '.'
					mx[0][cols-1] = 'c'
			elif(cols==1) :
				# should be one left at least
				if (mines < rows ):
					for i in range(mines) :
						mx[i][0] = '*'
					for i in range(mines, rows - 1) :
						mx[i][0] = '.'
					mx[rows-1][0] = 'c'
	elif (rows == 2 or cols == 2):
		# all but one mine
		if (mines == rows*cols -1 ) :
			for i in range(rows) :
				for j in range(cols) :
					mx[i][j] = '*'
			mx[rows-1][cols-1] = 'c'
		
		# only possible with even mines and should be minimally 4 open spaces
		elif ((not (mines%2)) and mines <= rows*cols-4):
			if(rows==2) :
				for i in range(mines/2) :
					mx[0][i] = '*'
					mx[1][i] = '*'
				for i in range(mines/2, cols - 1) :
					mx[0][i] = '.'
					mx[1][i] = '.'
				mx[0][cols-1] = 'c'
				mx[1][cols-1] = '.'
			elif(cols==2) :
				for i in range(mines/2) :
					mx[i][0] = '*'
					mx[i][1] = '*'
				for i in range(mines/2, rows - 1) :
					mx[i][0] = '.'
					mx[i][1] = '.'
				mx[rows-1][0] = 'c'
				mx[rows-1][1] = '.'
	else :
		if (mines == rows*cols - 1 ) :
			for i in range(rows) :
				for j in range(cols) :
					mx[i][j] = '*'
			mx[rows-1][cols-1] = 'c'
		else :
			leftover = rows*cols - mines
			if leftover == 4 :
				for i in range(rows):
					for j in range(cols):
						mx[i][j] = '*'
				mx[rows-2][cols-2]='.'
				mx[rows-2][cols-1]='.'
				mx[rows-1][cols-2]='.'
				mx[rows-1][cols-1]='c'
			elif leftover == 6 :
				for i in range(rows):
					for j in range(cols):
						mx[i][j] = '*'
				if rows > cols :
					mx[rows-3][cols-2]='.'					
					mx[rows-3][cols-1]='.'
					mx[rows-2][cols-2]='.'					
					mx[rows-2][cols-1]='.'
					mx[rows-1][cols-2]='.'
					mx[rows-1][cols-1]='c'
				else : 
					mx[rows-2][cols-3]='.'					
					mx[rows-1][cols-3]='.'
					mx[rows-2][cols-2]='.'					
					mx[rows-2][cols-1]='.'
					mx[rows-1][cols-2]='.'
					mx[rows-1][cols-1]='c'
				
			elif leftover >= 8  :
				for i in range(rows):
					for j in range(cols):
						mx[i][j] = '.'
				row = 0
				col = 0
				toggle = 0
				toggle_row = 0
				toggle_col = 0
				fillright = 0
				fillleft = 0
				while mines > 0 :
					if fillleft :
						if not toggle :
							mx[toggle_row][toggle_col] = '.'
							mx[row][col] = '*'
							mx[row+1][col] = '*'
							mines -=1
							toggle = 1
						else :
							mx[toggle_row][toggle_col] = '*'
							mines -=1
							col += 1
							toggle = 0

					elif fillright :
						if not toggle :
							mx[toggle_row][toggle_col] = '.'
							mx[row][col] = '*'
							mx[row][col+1] = '*'
							mines -=1
							toggle = 1
						else :
							mx[toggle_row][toggle_col] = '*'
							mines -=1
							row += 1
							toggle = 0
							if row == toggle_row :
								fillleft = 1
								col = 0
								row = rows-2
					elif ( row<rows-2 and col<cols-2 ) :
						mx[row][col] = '*'
						mines -= 1
						row+=1
					elif ( row >= rows-2 ) :
						if col+1 >= cols-2 :
							toggle_row = row-1
							toggle_col = col
							if row == 1:
								#print "special case"
								fillleft = 1
								row = rows - 2
								col = 0
							else :								
								fillright = 1
								row = 0
								col += 1
							#At edge
						else :
							row = 0
							col += 1
				mx[rows-1][cols-1] = 'c'
					
				
		
	return mx
	'''
	if( rows == 2 or cols == 2) :
		# Even nr of mines
		if not ( mines%2 ) :
	'''
	

def retrieveParams(line):
	params = line.split(" ")
	params = [ int(i) for i in params ]
	return params

if len(lines) :
	nrOfTests = int(lines[0])
	lines = lines[1:]
	for test in range(nrOfTests) :
		line = lines[0]
		lines = lines[1:]
		params = retrieveParams(line)
		rows = params[0]
		cols = params[1]
		mines = params[2]
		mx = getMatrix(params[0], params[1], params[2])
		outputstr = "Case #"+str(test+1)+":\n"
		if mx[0][0] != '0' :
			for row in range(rows) :
				rowstr = ""
				for col in range(cols) :
					rowstr += mx[row][col]
				outputstr += rowstr 
				outputstr += "\n"
		else :
			outputstr += "Impossible\n"
		print outputstr
		output.write(outputstr)
	
output.close()

