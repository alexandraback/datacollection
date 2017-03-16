#MMM, Google Code Jam Problem 3, Minesweeper

#Writegrid defined for hard writing cases
def writegrid(R, C, dotgrid, outfile):
	outfile.write("c")

	for row in range(R):
		for col in range(C):
			if ((row, col) in dotgrid):
				if (row,col)!=(0,0):
					outfile.write(".")
			else:
				outfile.write("*")
		outfile.write("\n")

infile = open("C-small-attempt0.in", "r")
outfile = open("output.txt", "w")

numtests = int(infile.readline())

for T in range(numtests):

	#Write the Case Number
	outfile.write("Case #"+str(T+1)+":\n")

	#Read the rows, columns, mines, and calculate the blank spaces
	(R, C, M) = map(int, infile.readline().split(' '))
	B = R*C-M

	#set up minesplaced for easy cases
	minesplaced = 0

	#set up dotgrid for hard cases
	dotgrid = list()
	dotgrid.append((0,0))
	dotgrid.append((1,0))
	dotgrid.append((0,1))
	dotgrid.append((1,1))

	#Special Case: 1 Row
	if R < 2:
		for col in range(C):
			if minesplaced<M:
				outfile.write("*")
				minesplaced+=1
			elif col == C-1:
				outfile.write("c\n")
			else:
				outfile.write(".")

	#Special Case: 1 Column
	elif C < 2:
		for row in range(R):
			if minesplaced<M:
				outfile.write("*\n")
				minesplaced+=1
			elif row == R-1:
				outfile.write("c\n")
			else:
				outfile.write(".\n")

	#Special Case: Bullseye
	elif B==1:
		for row in range(R):
			for col in range (C):
				if (row == R-1 and col == C-1):
					outfile.write("c")
				else:
					outfile.write("*")
			outfile.write("\n")

	#Special Case: 2 Rows
	elif R==2 and (B >=4) and (M%2 == 0):

		for col in range(2, C):
			if len(dotgrid)>=B:
				break
			dotgrid.append((0, col))
			dotgrid.append((1, col))
		
		writegrid(R, C, dotgrid, outfile)

	#Special Case: 2 Columns
	elif C==2 and (B>=4) and (M%2 == 0):

		for row in range (2, R):
			if len(dotgrid)>=B:
				break			
			dotgrid.append((row, 0))
			dotgrid.append((row, 1))

		writegrid(R, C, dotgrid, outfile)

	#Catch-all Case: 3x3 or greater, 6, 8, 9, or more
	
	elif (B>=8 or B==6 or B==4) and R>2 and C>2:

		#6
		if B>len(dotgrid):
			dotgrid.append((0,2))
			dotgrid.append((1,2))

		#8
		if B>len(dotgrid):
			dotgrid.append((2,0))
			dotgrid.append((2,1))

		#9 & fill L shape even or odd
		if B>len(dotgrid):
			if (B%2 != 0):
				dotgrid.append((2,2))

			for col in range(3, C):
				if len(dotgrid)>=B:
					break
				dotgrid.append((0, col))
				dotgrid.append((1, col))

			for row in range (3, R):
				if len(dotgrid)>=B:
					break			
				dotgrid.append((row, 0))
				dotgrid.append((row, 1))

		#if 9 spot isn't in add it
		if B>len(dotgrid):
			if not (2,2) in dotgrid:
				dotgrid.append((2,2))

		#fill in rest
		if B>len(dotgrid):
			for row in range(2,R):
				for col in range(2,C):
					if B>len(dotgrid) and ((row, col) != (2,2)):
						dotgrid.append((row,col))
				if len(dotgrid)==B:
					break

		writegrid(R, C, dotgrid, outfile)

	else:
		outfile.write("Impossible\n")