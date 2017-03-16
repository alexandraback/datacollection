def solver (tempdata):
	numbers = [int(integer) for integer in tempdata.split(" ")]
	r = numbers[0]
	c = numbers[1]
	m = numbers[2]
	
	if r == 1:
		outputfile.write("c")
		for blanks in range (1,c-m):
			outputfile.write(".")
		for mines in range (0,m):
			outputfile.write("*")
		outputfile.write("\n")
	elif c == 1:
		outputfile.write("c\n")
		for blanks in range (1,r-m):
			outputfile.write(".\n")
		for mines in range (0,m):
			outputfile.write("*\n")
	elif r*c-m==1:
		for columns in range (1,c):
			outputfile.write("*")
		outputfile.write("c\n")
		for rows in range (1,r):
			for columns in range (0,c):
					outputfile.write("*")
			outputfile.write("\n")
	elif (r*c-m) in (2,3,5,7):
		outputfile.write("Impossible\n")
	elif (r == 2 or c == 2) and (r*c-m)%2 != 0:
		outputfile.write("Impossible\n")
	elif r == 2:
		outputfile.write("c")
		for columns in range (1,c-m//2):
			outputfile.write(".")
		for columns in range (0,m//2):
			outputfile.write("*")
		outputfile.write("\n")
		for columns in range (0,c-m//2):
			outputfile.write(".")
		for columns in range (0,m//2):
			outputfile.write("*")
		outputfile.write("\n")
	elif c == 2:
		outputfile.write("c.\n")
		for rows in range (1,r-m//2):
			outputfile.write("..\n")
		for rows in range (0, m//2):
			outputfile.write("**\n")
	elif m==0:
		for columns in range (1,c):
			outputfile.write(".")
		outputfile.write("c\n")
		for rows in range (1,r):
			for columns in range (0,c):
					outputfile.write(".")
			outputfile.write("\n")
	elif r*c-m==4:
		for columns in range (2,c):
			outputfile.write("*")
		outputfile.write(".c\n")
		for columns in range (2,c):
			outputfile.write("*")
		outputfile.write("..\n")
		for rows in range (2,r):
			for columns in range (0,c):
					outputfile.write("*")
			outputfile.write("\n")
	else:
		while m>=c and r>3:
			for columns in range (0,c):
				outputfile.write("*")
			m=m-c
			r=r-1
			outputfile.write("\n")
		if m<=(c-2) and r>3:
			for columns in range (0,m):
				outputfile.write("*")
			for columns in range (0,c-m):
				outputfile.write(".")
			outputfile.write("\n")
			for rows in range (2,r):
				for columns in range (0,c):
					outputfile.write(".")
				outputfile.write("\n")
			for columns in range (1,c):
				outputfile.write(".")
			outputfile.write("c\n")
		elif m==(c-1) and r>3:
			for columns in range (0,m-1):
				outputfile.write("*")
			for columns in range (0,2):
				outputfile.write(".")
			outputfile.write("\n")
			for columns in range (0,1):
				outputfile.write("*")
			for columns in range (1,c):
				outputfile.write(".")
			outputfile.write("\n")	
			for rows in range (3,r):
				for columns in range (0,c):
					outputfile.write(".")
				outputfile.write("\n")
			for columns in range (1,c):
				outputfile.write(".")
			outputfile.write("c\n")
		elif r>3:
			for columns in range (0,m):
				outputfile.write("*")
			for columns in range (0,c-m):
				outputfile.write(".")
			outputfile.write("\n")
			for rows in range (2,r):
				for columns in range (0,c):
					outputfile.write(".")
				outputfile.write("\n")
			for columns in range (1,c):
				outputfile.write(".")
			outputfile.write("c\n")
		elif m%3 == 0:
			for columns in range (0,m//3):
				outputfile.write("*")
			for columns in range (m//3,c):
				outputfile.write(".")
			outputfile.write("\n")
			for columns in range (0,m//3):
				outputfile.write("*")
			for columns in range (m//3,c):
				outputfile.write(".")
			outputfile.write("\n")
			for columns in range (0,m//3):
				outputfile.write("*")
			for columns in range (m//3,c-1):
				outputfile.write(".")
			outputfile.write("c\n")
		elif m%3 == 1:
			for columns in range (0,(m-1)//3+1):
				outputfile.write("*")
			for columns in range ((m-1)//3+1,c):
				outputfile.write(".")
			outputfile.write("\n")
			for columns in range (0,(m-1)//3):
				outputfile.write("*")
			for columns in range ((m-1)//3,c):
				outputfile.write(".")
			outputfile.write("\n")
			for columns in range (0,(m-1)//3):
				outputfile.write("*")
			for columns in range ((m-1)//3,c-1):
				outputfile.write(".")
			outputfile.write("c\n")
		else:
			for columns in range (0,(m-2)//3+2):
				outputfile.write("*")
			for columns in range ((m-2)//3+2,c):
				outputfile.write(".")
			outputfile.write("\n")
			for columns in range (0,(m-2)//3):
				outputfile.write("*")
			for columns in range ((m-2)//3,c):
				outputfile.write(".")
			outputfile.write("\n")
			for columns in range (0,(m-2)//3):
				outputfile.write("*")
			for columns in range ((m-2)//3,c-1):
				outputfile.write(".")
			outputfile.write("c\n")
		
inputfile = open('C-large.in')
outputfile = open('C-large.txt', 'w')

numberofcases = inputfile.readline()     
for tempnumber in range(1, int(numberofcases)+1):
	tempdata = inputfile.readline().rstrip("\n")
	outputfile.write("Case #%i:\n" % (tempnumber))
	solver(tempdata)
	
inputfile.close()
outputfile.close()