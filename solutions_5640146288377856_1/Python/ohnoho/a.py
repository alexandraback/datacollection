inputFile = open('A-large.in', 'r')
inString = inputFile.read()
inputLines = inString.split('\n')
inputLines.pop(0)
output = ''
case = 1

for line in inputLines:
	data = line.split(' ')
	if len(data) <= 1:
		continue
	data = map(int, data)
	rows = data[0]
	columns = data[1] 
	ship = data[2]
# Bailouts	
	score = 0
	if ship == 1:
		score = rows * columns
	elif ship == columns:
		score = rows + columns - 1
	else: 
		dividend = columns / ship
		score = dividend
		remainingCells = columns - score * ship
		score += ship
		if remainingCells == ship or remainingCells == 0:
			score -= 1
		score += ((rows - 1) * dividend)
	output += ('Case #' + str(case) + ': ' + str(score) + '\n')	
	case += 1	
outputFile = open('out3.out', 'w')
outputFile.write(output)