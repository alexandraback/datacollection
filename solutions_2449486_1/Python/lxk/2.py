fin = open('input.txt')
lines = fin.read().split("\n")

countTests = int(lines[0])
curLine = 1

for testCase in range(1, countTests + 1):
	l1 = lines[curLine].split()

	numRows = int(l1[0])
	numCols = int(l1[1])

	field = []
	for y in range(0, numRows):
		line = lines[curLine + y + 1]
		field.extend([int(x) for x in line.split()])

	rows = [field[i * numCols:i * numCols + numCols] for i in range(0, numRows)]
	maxRows = [max(row) for row in rows]

	cols = [field[i::numCols][0:numRows] for i in range(0, numCols)]
	maxCols = [max(col) for col in cols]

	valid = True
	for y in range(0, numRows):
		for x in range(0, numCols):
			val = field[y * numCols + x]
			if maxRows[y] != val and maxCols[x] != val:
				valid = False
				break

		if not valid:
			break

	print "Case #" + str(testCase) + ": " + ("YES" if valid else "NO")

	curLine += numRows + 1
	pass