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

def debugCharMatrix(matrix):
	R = len(matrix)
	C = len(matrix[0])
	for i in range(R):
		line = ''
		for j in range(C):
			line = line + matrix[i][j] + ' '
		print(line)

def judgeGame(matrix):
	N = len(matrix)
	full = True

	for i in range(N):
		x_win = True
		o_win = True
		for j in range(N):
			c = matrix[i][j]
			if '.' == c:
				x_win = False
				o_win = False
				full = False
				break
			if 'X' == c:
				o_win = False
			elif 'O' == c:
				x_win = False
		if x_win:
			return 'X won'
		if o_win:
			return 'O won'

	for j in range(N):
		x_win = True
		o_win = True
		for i in range(N):
			c = matrix[i][j]
			if '.' == c:
				x_win = False
				o_win = False
				break
			if 'X' == c:
				o_win = False
			elif 'O' == c:
				x_win = False
		if x_win:
			return 'X won'
		if o_win:
			return 'O won'

	x_win = True
	o_win = True
	for i in range(N):
		c = matrix[i][i]
		if '.' == c:
			x_win = False
			o_win = False
			break
		if 'X' == c:
			o_win = False
		elif 'O' == c:
			x_win = False
	if x_win:
		return 'X won'
	if o_win:
		return 'O won'

	x_win = True
	o_win = True
	for i in range(N):
		c = matrix[i][N - 1 - i]
		if '.' == c:
			x_win = False
			o_win = False
			break
		if 'X' == c:
			o_win = False
		elif 'O' == c:
			x_win = False
	if x_win:
		return 'X won'
	if o_win:
		return 'O won'

	if full:
		return 'Draw'
	else:
		return 'Game has not completed'

FILE_NAME = sys.argv[1]

input = open(FILE_NAME + '.in', 'r')
output = open(FILE_NAME + '.out', 'w')

testcases = int(input.readline().strip())

for testcase in range(1, testcases + 1):
	matrix = getCharMatrix(input, 4)
	line = input.readline().strip()

	result = 'Case #' + str(testcase) + ': ' + judgeGame(matrix)
	writeline(output, result)

input.close()
output.close()
