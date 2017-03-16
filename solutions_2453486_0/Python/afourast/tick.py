import sys
import re

def transpose(mat):
	return map(list, zip(*mat))

def winLine(line,playerSymbol,balader):
	assert(len(line)==4)
	return all( item == playerSymbol or item==balader for item in line)

def printCase(case):
	for row in case:
		print row

def hasPlayerWon(gameMap,playerSymbol,balader):
	for line in gameMap:
		#~ print line
		if winLine(line,playerSymbol,balader):
			return True
			
	for line in transpose(gameMap):
		if winLine(line,playerSymbol,balader):
			return True
	
	diag1= [ gameMap[i][i] for i in range(4) ] 
	if(winLine(diag1,playerSymbol,balader)):
		return True

	diag2= [ gameMap[3-i][i] for i in range(4) ]
	if(winLine(diag2,playerSymbol,balader)):
		return True
		
	return False

def gameUnfinished(case):
	for line in case:
		if '.' in line:
			return True
	return False

with open(sys.argv[1]) as inFile:
	N = int(inFile.readline())
	cases = []
	for i in range(N):
		cases.append([])
		for j in range(4):
			cases[i].append(inFile.readline().strip())
		inFile.readline()

#~ for case in cases:
	#~ printCase(case)

solutions=[]
for case in cases:
	if hasPlayerWon(case,'O','T'):
		solutions.append('O won')
	elif hasPlayerWon(case,'X','T'):
		solutions.append('X won')
	elif gameUnfinished(case):
		solutions.append('Game has not completed')
	else:
		solutions.append('Draw')
	
#~ print solutions

with open(sys.argv[2],'w') as outFile :	
	for index,solution in enumerate(solutions):
		print solution
		outFile.write( 'Case #' + str(index+1) + ': ' + str(solution) + '\n')

