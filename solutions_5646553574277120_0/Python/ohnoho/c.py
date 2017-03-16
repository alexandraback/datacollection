inputFile = open('C-small-attempt1.in', 'r')
inString = inputFile.read()
inputLines = inString.split('\n')
inputLines.pop(0)
output = ''
case = 1
lineNumber = 0

multiplier = 0
maxValue = 0

def nextValue(a, index):
	if len(a) > index:
		return a[index]
	return -1

for line in inputLines:
	if lineNumber == 0:
		data = line.split(' ')
		if len(data) <= 1:
			continue;
		data = map(int, data)
		multiplier = data[0]
		maxValue = data[2]
		lineNumber = 1
		# print data
	else:
		data = line.split(' ')
		data = map(int, data)
		# print data
		denominations = data
		reach = 0
		next = denominations[0]
		index = 0
		insertions = 0
		for i in range(1, maxValue):
			if next > 0 and i == next:
				reach += (i * multiplier)
				index += 1
				next = nextValue(denominations, index)
				# print 'extending reach for pre-existing' + str(reach) + ' for i ' + str(i) + '. next is now ' + str(next)
			if i > reach:
				reach += (i * multiplier)
				denominations.insert(index, i)
				index += 1
				insertions += 1
				next = nextValue(denominations, index)
				# print 'inserting ' + str(i) + ' to extend reach to ' + str(reach) + '. next is now ' + str(next)
		# print ('Case #' + str(case) + ': ' + str(insertions) + '\n')
		output += ('Case #' + str(case) + ': ' + str(insertions) + '\n')
		lineNumber = 0	
		case += 1
outputFile = open('out1.out', 'w')
outputFile.write(output)