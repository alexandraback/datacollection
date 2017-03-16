import sys

ECHO_ON = True

def writeline(output, line):
	if ECHO_ON:
		print(line)
	output.write(line + '\n')

def getCharMatrix(input, R):
	matrix = []
	for i in range(R):
		line = input.readline().strip()
		matrix.append(line)
	return matrix;

def getIntMatrix(input):
	line = input.readline().strip()
	elements = line.split(' ')
	R = int(elements[0])
	C = int(elements[1])
	matrix = []
	for i in range(R):
		line = input.readline().strip()
		elements = line.split(' ')
		row = []
		for j in range(C):
			row.append(int(elements[j]))
		matrix.append(row)
	return matrix;

def debugCharMatrix(matrix):
	R = len(matrix)
	C = len(matrix[0])
	for i in range(R):
		line = ''
		for j in range(C):
			line = line + matrix[i][j] + ' '
		print(line)

def debugIntMatrix(matrix):
	R = len(matrix)
	C = len(matrix[0])
	for i in range(R):
		line = ''
		for j in range(C):
			line = line + str(matrix[i][j]) + ' '
		print(line)

def judgeLawn(matrix):
	R = len(matrix)
	C = len(matrix[0])
	rowMax = [0] * R
	colMax = [0] * C
	for i in range(R):
		for j in range(C):
			rowMax[i] = max(rowMax[i], matrix[i][j])
			colMax[j] = max(colMax[j], matrix[i][j])
	for i in range(R):
		for j in range(C):
			value = matrix[i][j]
			if value != rowMax[i] and value != colMax[j]:
				return 'NO'
	return 'YES'

FILE_NAME = sys.argv[1]

input = open(FILE_NAME + '.in', 'r')
output = open(FILE_NAME + '.out', 'w')

testcases = int(input.readline().strip())

for testcase in range(1, testcases + 1):
	matrix = getIntMatrix(input)
	result = 'Case #' + str(testcase) + ': ' + judgeLawn(matrix)
	writeline(output, result)

input.close()
output.close()
