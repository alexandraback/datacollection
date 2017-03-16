import sys

input = open(sys.argv[1], 'r')
t = int(input.readline()[:-1])
for x in range(1, t+1):
	line = input.readline()[:-1].split()
	R = int(line[0])
	C = int(line[1])
	M = int(line[2])
	blanks = R * C - M
	if (R==1) or (C==1):
		print "Case #" + str(x) + ":"
		if (R==1):
			print "c" + "." * (blanks-1) + "*" * (C-blanks)
		else:
			print "c"
			for y in range(0, blanks-1):
				print "."
			for y in range(0, R-blanks):
				print "*"
	elif (blanks == 1):
		print "Case #" + str(x) + ":"
		print "c" + (C-1) * "*"
		for y in range(0, R-1):
			print C * "*"
	elif (blanks >= 4):
		rows = 2
		columns = 2
		leftover = 0
		foundMatch = False
		while (not foundMatch):
			leftover = blanks - rows * columns
			if (leftover < 0 or columns > C):
				rows += 1
				columns = 2
			elif leftover == 0:
				foundMatch = True
			elif (rows!=R and columns!=C):
				if (leftover >=2 and (leftover <= columns or leftover <= rows)):
					foundMatch = True
				elif (leftover < rows + columns and leftover >= 5):
					foundMatch = True
				else:
					columns += 1
			elif (rows==R and (leftover <= rows and leftover >1)):
				foundMatch = True
			elif (columns==C and (leftover <= columns and leftover >1)):
				foundMatch = True
			else:
				columns += 1
			if rows > R:
				break
		if (not foundMatch):
			print "Case #" + str(x) + ":"
			print "Impossible"
		else:
			# print rows
			# print columns
			# print leftover
			print "Case #" + str(x) + ":"
			starRows = R - rows - 1
			if starRows < 0:
				starRows = 0
			for y in range(0, starRows):
				print C * "*"
			if leftover <= columns:
				print (C-leftover) * "*" + leftover * "."
				for y in range(0, rows-1):
					print (C-columns) * "*" + columns * "."
				print (C - columns) * "*" + (columns-1) * "." + "c"
			elif leftover <= rows:
				for y in range(0, rows-leftover):
					print (C-columns) * "*" + columns * "."
				for y in range(0, leftover-1):
					print (C-columns-1) * "*" + (columns +1) * "."
				print (C-columns-1) * "*" + (columns) *"." + "c"
			else:
				if rows < columns:
					extra = leftover-2
					while C < extra:
						extra-=1
				else:
					extra = 3
					while R < (leftover - extra):
						extra+=1
				print (C-columns-1) * "*" + (extra) * "." + (columns - extra+ 1) * "*"
				leftover -= extra
				for y in range(0, rows-1):
					if leftover > 0:
						print (C - columns -1) * "*" + (columns + 1) * "."
						leftover-=1
					else:
						print (C - columns) * "*" + (columns) * "."
				if leftover > 0:
					print (C - columns -1) * "*" + (columns) * "." + "c"
				else:
					print (C - columns) * "*" + (columns - 1) * "." + "c"
		
	else:
		print "Case #" + str(x) + ":"
		print "Impossible"




