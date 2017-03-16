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

PALINDROMES = [1]
def nextPalindrome(number):
	while (number >= PALINDROMES[len(PALINDROMES) - 1]):
		X = PALINDROMES[len(PALINDROMES) - 1];
		last = str(X)
		length = len(last)

		allNine = True
		for i in range(length):
			if '9' != last[i]:
				allNine = False
				break

		for i in range(length // 2):
			X = X // 10
		X = X + 1

		next = str(X)
		buffer = next

		if allNine:
			for i in range(length // 2):
				buffer = buffer + '0'
			PALINDROMES.append(1 + int(buffer))
		else:
			for i in range((length // 2) - 1, -1, -1):
				buffer = buffer + next[i]
			PALINDROMES.append(int(buffer))

	begin = 0
	end = len(PALINDROMES) - 1
	middle = (begin + end) // 2

	while begin != end:
		if number >= PALINDROMES[middle]:
			begin = middle + 1
		else:
			end = middle
		middle = (begin + end) // 2

	return PALINDROMES[middle]

def isPalindrome(number):
	if number == nextPalindrome(number - 1):
		return True
	return False

FILE_NAME = sys.argv[1]

input = open(FILE_NAME + '.in', 'r')
output = open(FILE_NAME + '.out', 'w')

fair = [False] * 1001
i = 1
i2 = i * i
while i2 < 1001:
	if isPalindrome(i) and isPalindrome(i2):
		fair[i2] = True
	i = i + 1
	i2 = i * i

fairCount = [0] * 1001
count = 0
for i in range(1001):
	if fair[i]:
		count = count + 1
	fairCount[i] = count

testcases = int(input.readline().strip())

for testcase in range(1, testcases + 1):
	line = input.readline().strip()
	elements = line.split(' ')
	A = int(elements[0])
	B = int(elements[1])
	result = 'Case #' + str(testcase) + ': ' + str(fairCount[B] - fairCount[A - 1])
	writeline(output, result)

input.close()
output.close()
