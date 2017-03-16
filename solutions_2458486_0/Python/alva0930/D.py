import sys
import collections

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
	line = str(number)
	for i in range(len(line)):
		if line[i] != line[len(line) - 1 - i]:
			return False
	return True

def sqrt(X):
	answer = 1
	interval = 1
	for i in range(len(str(X)) // 2, 0, -1):
		interval = interval * 10
	while interval >= 1:
		while answer * answer <= X:
			answer = answer + interval
		answer = answer - interval
		interval = interval //10
	return answer

def sqrt_ceiling(X):
	answer = sqrt(X)
	if answer * answer == X:
		return answer
	return answer + 1

def openChests(locks, keys, chests, path, map):
	allOpen = True
	for i in locks:
		if 1 == i:
			allOpen = False
			break

	if allOpen:
		return path

	key = 0
	for i in locks:
		key = key << 1
		key = key + i
	key = str(key) + ';'
	for i in keys:
		key = key + str(keys[i]) + ';'
	if key in map:
		return map[key]

	L = len(locks)
	K = len(keys)

	for l in range(L):
		if 1 == locks[l]:
			type = chests[l][0]
			if 0 != keys[type]:
				locks[l] = 0
				keys[type] = keys[type] - 1
				for k in range(1, len(chests[l]), 1):
					kk = chests[l][k]
					if kk in keys:
						keys[kk] = keys[kk] + 1

				result = openChests(locks, keys, chests, path + ' ' + str(l + 1), map)
				if ' IMPOSSIBLE' != result:
					return result

				locks[l] = 1
				keys[type] = keys[type] + 1
				for k in range(1, len(chests[l]), 1):
					kk = chests[l][k]
					if kk in keys:
						keys[kk] = keys[kk] - 1

	map[key] = ' IMPOSSIBLE'
	return ' IMPOSSIBLE'

FILE_NAME = sys.argv[1]

input = open(FILE_NAME + '.in', 'r')
output = open(FILE_NAME + '.out', 'w')

testcases = int(input.readline().strip())

for testcase in range(1, testcases + 1):
	line = input.readline().strip()
	elements = line.split(' ')
	K = int(elements[0])
	N = int(elements[1])

	locks = [1] * N
	keys = dict()
	chests = []
	path = ''
	map = dict()

	keyLine = input.readline().strip()

	for c in range(N):
		line = input.readline().strip()
		elements = line.split(' ')
		Ti = int(elements[0])
		Ki = int(elements[1])
		chest = []
		chest.append(Ti)
		for i in range(Ki):
			chest.append(int(elements[i + 2]))
		chests.append(chest)
		keys[Ti] = 0

	keys = collections.OrderedDict(sorted(keys.items()))

	elements = keyLine.split(' ')
	for i in range(K):
		k = int(elements[i])
		if k in keys:
			keys[k] = keys[k] + 1

	print(keys)
	print(chests)

	result = 'Case #' + str(testcase) + ':' + openChests(locks, keys, chests, path, map)
	writeline(output, result)

input.close()
output.close()
