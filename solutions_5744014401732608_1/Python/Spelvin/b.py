def topline(b,m):
# assumes m <= 2**(b-2)
	if m == 1:
		return '0' * (b-1) + '1'
	else:
		partialstring = bin(m-1)[2:]
		return '0' + ('0' * (b-2-len(partialstring))) + partialstring + '1'

def anyline(buildings,row,m):
	if row == 1:
		return topline(buildings,m) 
	if row == buildings:
		return '0' * buildings
	else:
		return ('0' * row) + ('1' * (buildings - row))

import sys
with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()
		
with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):
		pair = inputLines.pop(0).rstrip().split(' ')
		b = int(pair[0])
		m = int(pair[1])
		if m > 2**(b-2):
			fileOUT.write('Case #' + str(num+1) + ': ' + 'IMPOSSIBLE' + '\n')
		else:
			fileOUT.write('Case #' + str(num+1) + ': ' + 'POSSIBLE' + '\n')
			for i in range(1,b+1):
				fileOUT.write(anyline(b,i,m) + '\n')