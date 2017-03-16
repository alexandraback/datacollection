#! /usr/bin/python
from math import sqrt

def printMatrix(shortEdge, longEdge, fullMineLineNum, centralList, cellLineNum, cellAmountEachLine, matrix):
	del matrix[:]
	matrix.extend(['*' * shortEdge for x in range(fullMineLineNum)] + centralList +\
		['.' * cellAmountEachLine + '*' * (shortEdge - cellAmountEachLine)] * cellLineNum)
	matrix[longEdge - 1] = 'c' + matrix[longEdge - 1][1:]

if __name__ == "__main__":
	outputFile = open("C.out", "w") 
	data = [[int(numStr) for numStr in line.split()] for line in open("C.in", "r")]
	numOfCase = int(data[0][0])
	for caseIndex in range(numOfCase):
		row = data[caseIndex + 1][0]
		col = data[caseIndex + 1][1]
		mine = data[caseIndex + 1][2]
		cell = row * col - mine
		shortEdge = min(col, row)
		longEdge = max(col, row)

		matrix = ['.' * shortEdge for x in range(longEdge)]
		
		if mine == 0:
			matrix[0] = 'c' + matrix[0][1:]
			possible = True
		else:
			if shortEdge == 1:
				matrix = ['*'] * mine + matrix[mine : -1] + ['c']
				possible = True
			elif shortEdge == 2:
				if cell == 1:
					matrix = ['c*'] + ['**'] * (longEdge - 1)
					possible = True
				elif cell == 2 or cell % 2 == 1:
					possible = False
				else:
					matrix = ['c.'] + ['..'] * (cell / 2 - 1) + ['**'] * (mine / 2)
					possible = True
			else:
				if cell >= shortEdge ** 2:
					printMatrix(shortEdge, longEdge, mine / shortEdge,
						['.' * (shortEdge - 1) + '*'] * (mine % shortEdge),
						longEdge - mine / shortEdge - mine % shortEdge, shortEdge, matrix)
					possible = True
				else:
					cellEdge = int(sqrt(cell))
					if cell == cellEdge ** 2:
						printMatrix(shortEdge, longEdge, longEdge - cellEdge, [], cellEdge, cellEdge, matrix)
						possible = True
					else:
						cellEdge += 1
						if cellEdge <= 2:
							possible = False
						else:
							leftMineNum = cellEdge ** 2 - cell
							centralList = []

							if leftMineNum >= cellEdge:
								leftMineNum -= cellEdge
								centralList += ['*' * shortEdge]
							
							while leftMineNum > 0 and len(centralList) < cellEdge - 2:
								if leftMineNum <= cellEdge - 2:
									centralList += ['.' * (cellEdge - leftMineNum) + '*' * (shortEdge - cellEdge + leftMineNum)]
									leftMineNum = 0;
								else:
									leftMineNum -= (cellEdge - 2)
									centralList += ['.' * 2 + '*' * (shortEdge - 2)]
							else:
								if leftMineNum == 0:
									printMatrix(shortEdge, longEdge, longEdge - cellEdge, centralList, cellEdge - len(centralList), cellEdge, matrix)
									possible = True
								else:
									possible = False
		if possible:
			if shortEdge != col:
				matrix = [''.join(line) for line in zip(*matrix)]
			content = '\n'.join(matrix)
		else:
			content = "Impossible"
		outputContent = "Case #%d:\n%s\n" % (caseIndex + 1, content)
		#print outputContent
		outputFile.write(outputContent)
	outputFile.close()
