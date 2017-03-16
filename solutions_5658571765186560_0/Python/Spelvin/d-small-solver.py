def solver(x,r,c):
	if x == 1:
		return 'GABRIEL'
	if x == 2:
		if (r*c)%2 == 0:
			return 'GABRIEL'
		else:
			return 'RICHARD'
	if x == 3:
		if (r*c)%3 == 0 and r > 1 and c > 1:
			return 'GABRIEL'
		else:
			return 'RICHARD'
	if x == 4:
		if r+c > 6:
			return 'GABRIEL'
		else:
			return 'RICHARD'
		
import sys

with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()

inputLines = [line.strip() for line in inputLines]	

with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):	
		inputlist = inputLines.pop(0).rstrip().split(' ')
		x = int(inputlist[0])
		r = int(inputlist[1])
		c = int(inputlist[2])
		fileOUT.write('Case #' + str(num+1) + ': ' + solver(x,r,c) + '\n')